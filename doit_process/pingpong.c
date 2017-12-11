#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <errno.h>
#include <fcntl.h>

#define NAME_POSIX "/my_mq"
#define PING 1
#define PONG 0

int main(void)
{
    struct mq_attr attr;
    char value[5] = {0};
    unsigned int prio = 0;
    int child = 0;
    int status = PING;
    mqd_t mqdes;

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 5;

    mqdes = mq_open(NAME_POSIX, O_NONBLOCK|O_CREAT|O_RDWR, 0666, &attr);
    if(mqdes == (mqd_t)-1)
        perror("mqopen fail \n");

    child = fork();

    while(1)
    {
        if(child != 0)
        {
            if(mq_receive(mqdes, value, 5, &prio) != -1)
                printf("Parent process(%d) : %s \n", getpid(), value);

            if(mq_send(mqdes, "ping", 5, 3) == -1)
                perror("Parent: message send failed: ");

            sleep(1);
        }
        else
        {
            if(mq_receive(mqdes, value, 5, &prio) != -1)
            {
                printf("Child process(%d) : %s \n", getpid(), value);
                if(mq_send(mqdes, "pong", 5, 2) == -1)
                    perror("Child: pong send failed: ");
            }
            sleep(1);
        }
    }

    mq_close(mqdes);
    mq_unlink(NAME_POSIX);

    return 0;
}
