#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>

#define NAME_POSIX "/my_mq"

int main(void)
{
    struct mq_attr attr;
    int value = 0;
    unsigned int prio;
    int child = 0;
    mqd_t mqdes;

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 8;

    mqdes = mq_open(NAME_POSIX, O_CREAT|O_RDWR, 0666, &attr);
    if(mqdes == (mqd_t)-1)
        perror("mqopen fail \n");

    child = fork();
    if(child == 0)
    {
        printf("CHILD SEND \n");
        value = 1000;
        if(mq_send(mqdes, (char *)&value, 8, prio) == -1)
            perror("Child send fail \n");
    }
    else
    {
        printf("PARENT RECV \n");
        if(mq_receive(mqdes, (char *)&value, 8, &prio) == -1)
            perror("Parent receive fail \n");
        printf("Received value: %d \n", value);
    }

    mq_close(mqdes);
    mq_unlink(NAME_POSIX);

    return 0;
}
