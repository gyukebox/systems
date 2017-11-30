#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>

#define NAME_POSIX "/my_mq"

int main(void)
{
    struct mq_attr attr;
    char value[5];
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
        if(mq_receive(mqdes, (char *)&value, 8, &prio) != -1)
            printf("%s \n", value);

        strcpy(value, "ping");
        if(mq_send(mqdes, (char *)&value, 8, prio) == -1)
            perror("Child send fail \n");

        sleep(1);
    }
    else
    {
        if(mq_receive(mqdes, (char *)&value, 8, &prio) != -1)
        {
            printf("%s \n", value);

            strcpy(value, "pong");
            if(mq_send(mqdes, (char *)value, 8, prio) == -1)
                perror("Parent send fail \n");
        }
    }

    mq_close(mqdes);
    mq_unlink(NAME_POSIX);

    return 0;
}
