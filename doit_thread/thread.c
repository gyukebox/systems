#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int tid = pthread_self();
    int i;

    for(i = 0; i < 10; i++)
    {
        printf("From thread %d : i = %d \n", tid, i);
        sleep(1);
    }
}

int main(void)
{
    pthread_t thread;
    int status;
    int i;

    /* 스레드를 생성해 볼께요 */
    status = pthread_create(&thread, NULL, thread_function, NULL);
    if(status != 0)
    {
        perror("Failed to create thread");
        exit(status);
    }

    for(i = 0; i < 50; i++)
    {
        printf("From main thread : i = %d \n", i);
    }

    pthread_join(thread, (void **)&status);
    printf("Thread terminated with status %d \n", status);

    return 0;
}
