#include "ku_psort.h"


int main(int argc, char **argv){
	pid_t pid = 0;
	FILE *fp;
	int num_integer = atoi(argv[1]);
	int num_process = atoi(argv[2]);
	int b,i;
	int a = 0;

	char filename[20];
	strcpy(filename, argv[3]);
	number = (int *)malloc(sizeof(int) * num_integer);
	fp = fopen(filename, "r");

	if(fp == NULL){
		perror("open file error\n");
		exit(1);
	}

	while(fscanf(fp, "%d\n", &b) != EOF){
			number[a++] = b;
	}

	fclose(fp);
	
	struct mq_attr attr;
	unsigned int prio = 0;
	mqd_t mqdes;
	int start; 
	int end;
	int range; // end - start
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = sizeof(int) * range;
	
	mqdes = mq_open(NAME_POSIX, O_CREAT|O_RDWR, 0666, &attr);
	if(mqdes < 0){
		perror("open error");
		exit(1);
	}

	for(i = 0; i < num_process; i++){
		if( i + 1 == num_process){
			start = num_integer / num_process * i;
			end = num_integer;
			range = end - start;
		} else {
			start = num_integer / num_process * i;
			end = num_integer / num_process * (i + 1);
			range = end - start;
		}

		pid = fork();
		if(pid == 0){
			sort(start, end);
			if(mq_send(mqdes, (char *)(number + start), sizeof(int) *range, prio) < 0){
				perror("send error\n");
				exit(1);
			}
			exit(1);
		}
		else{
			wait(NULL);
			if(mq_receive(mqdes, (char *)(number + start),  attr.mq_msgsize, &prio) < 0){
				perror("receive error\n");
				exit(1);
			}
		}
		merge(0, start, end);
	}

	mq_close(mqdes);
	mq_unlink(NAME_POSIX);
	fp = fopen(argv[4], "w");
	if(fp == NULL ){
		perror("fail to open file\n");
	}

	for(i = 0; i < num_integer; i++){
		fprintf(fp, "%d\n", number[i]);
	}
	fclose(fp);
	free(number);
	return 0;
}


void sort(int start, int end){
	if((end - start) < 2){
		return;
	}
	int mid = (start + end) / 2; 
	sort(start, mid);
	sort(mid, end);
	merge(start, mid, end);
}

void merge(int start, int mid, int end){
	int *tmp = (int *)malloc(sizeof(int) * end);
	memcpy(tmp, number, sizeof(int) * end);
	int l1, l2, i;

	for(l1 = start, l2 = mid, i = start; ; i++){
		if(l1>=mid) {
			for(;;) {
				if(l2<end)
					memmove(&number[i++], &tmp[l2++], sizeof(int));
				else
					break;
			}
			break;
		}
		if(l2>=end) {
			for(;;) {
				if(l1<mid)
					memmove(&number[i++], &tmp[l1++], sizeof(int));
				else
					break;
			}
			break;
		}
		if(tmp[l1] <= tmp[l2]){
			number[i] = tmp[l1];
			l1++;
		}
		else{
			number[i] = tmp[l2];
			l2++;
		}
	}
	free(tmp);
}
