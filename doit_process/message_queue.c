#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mqueue.h>

int main(void)
{
    pid_t pid;
    struct mq_attr attr;
    mqd_t mqdes;
    unsigned int prio;
    char *message;
    int numbers[10];

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(numbers);

    mqdes = mq_open("/test_mq", O_CREAT|O_RDWR, 0666, &attr);

    pid = fork();
    if(pid < 0)
    {
        perror("fork failed: ");
        exit(pid);
    }
    else if(pid == 0)
    {
        int i;
        int status;
        
        for(i = 0; i < 10; i++)
        {
            numbers[i] = (i + 1) * (i + 1);
        }
        printf("CHILD SEND \n");
        
        status = mq_send(mqdes, (char *)&numbers, sizeof(int) * 10, prio);
        exit(status);
    }
    else
    {
        int i;
        int status;
        wait(&status);
        printf("Child process exited with status %d \n", WEXITSTATUS(status));

        status = mq_receive(mqdes, (char *)numbers, sizeof(int) * 10, &prio);
        if(status == -1)
        {
            perror("Failed to receieve message: ");
        }

        for(i = 0; i < 10; i++)
        {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    mq_close(mqdes);
    mq_unlink("/test_mq");

    return 0;
}
