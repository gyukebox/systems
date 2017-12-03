/*
 * ku_psort.c
 * performs sorting of integers by multi-processing
 * written by Byeong Gyu Choi
 */

#include "ku_psort.h"

/*
 * main function to execute whole program
 * int argc : value must be 5
 * char **argv : values must be, in order,
 * 1. Total amount of number(s) to be sorted
 * 2. Total number of processes
 * 3. Name of input file
 * 4. Name of output file
 */
int main(int argc, char **argv)
{
    pid_t pid = 0;
    FILE *fp;
    int total_numbers;
    int num_processes;
    int i;

    if(argc != 5)
    {
        perror("Invalid Argument!");
        exit(1);
    }

    total_numbers = atoi(argv[1]);
    num_processes = atoi(argv[2]);

    numbers = (int *)malloc(sizeof(int) * total_numbers);
    fp = fopen(argv[3], "r");
    if(fp == NULL)
    {
        perror("Failed to open file: ");
        exit(1);
    }

    /* read numbers and store into number array */
    i = 0;
    while(!feof(fp))
    {
        if(fscanf(fp, "%d", (numbers + i)) != 1)
        {
            break;
        }
        i++;
    }

    fclose(fp);

    for(i = 0; i < num_processes; i++)
    {
        struct mq_attr attr;
        mqd_t mqdes;
        unsigned int prio;

        int start_pos;
        int end_pos;
        int status;

        /* define start and end position */
        start_pos = total_numbers / num_processes * i;
        end_pos = total_numbers / num_processes * (i + 1);
        if(i == num_processes - 1)
        {
            end_pos = total_numbers;
        }


        attr.mq_maxmsg = 10;
        attr.mq_msgsize = sizeof(int) * (end_pos - start_pos);
        mqdes = mq_open(NAME_POSIX, O_CREAT|O_RDWR, 0666, &attr);

        pid = fork();
        if(pid == 0)
        {
            /* sort */
            sort(start_pos, end_pos);

            /* send data to parent process */
            status = mq_send(mqdes, (char *)(numbers + start_pos), sizeof(int) * (end_pos - start_pos), prio);
            if(status != 0)
            {
                perror("Failed to send message: ");
            }
            exit(status);
        }
        else
        {
            wait(NULL);

            /* receive data from child process */
            status = mq_receive(mqdes, (char *)(numbers + start_pos), attr.mq_msgsize, &prio);
            if(status == -1)
            {
                perror("Failed to receieve message: ");
                exit(status);
            }
        }

        /* merge */
        if(i > 0)
        {
            merge(0, start_pos, end_pos);
        }

        mq_close(mqdes);
        mq_unlink(NAME_POSIX);
    }

    /* write to output file */
    fp = fopen(argv[4], "w");
    if(fp == NULL)
    {
        perror("Failed to open file: ");
        exit(1);
    }

    for(i = 0; i < total_numbers; i++)
    {
        fprintf(fp, "%d", numbers[i]);
        fputs("\n", fp);
    }

    fclose(fp);

    free(numbers);
    return 0;
}
/*
 * sort
 * sorts given sub-array (by merge sort)
 * param int left : left boundary of array(included in sorting)
 * param int right : right boundary of array(excluded in sorting)
 * return : void
 */
void sort(int left, int right)
{
    if((right - left) < 2)
        return;

    sort(left, left + (right - left) / 2);
    sort(left + (right - left) / 2, right);

    merge(left, left + (right - left) / 2,  right);
}
/*
 * merge
 * merges sub-sorted array
 * param int first_start : start index of first section
 * param int second_start : start index of second section, which is equal to end of first section
 * param int second_end : end index of second section
 * return : void
 */
void merge(int first_start, int second_start, int second_end)
{
    int i = first_start;
    int j = second_start;
    int index = first_start;

    /* making a copy */
    int *copy = (int *)malloc(sizeof(int) * second_end);
    memcpy(copy, numbers, sizeof(int) * second_end);

    while(1)
    {
        if(i >= second_start)
        {
            memmove(&numbers[index], &copy[j], sizeof(int) * (second_end - j));
            break;
        }
        if(j >= second_end)
        {
            memmove(&numbers[index], &copy[i], sizeof(int) * (second_start - i));
            break;
        }
        if(copy[i] > copy[j])
        {
            numbers[index] = copy[j];
            index++;
            j++;
        }
        else
        {
            numbers[index] = copy[i];
            index++;
            i++;
        }
    }

    free(copy);
}
