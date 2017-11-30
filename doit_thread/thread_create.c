#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *data)
{
    int id;
    int i = 0;

    id = *((int *)data);

    while(1)
    {
        printf("(%lu)%d : %d \n", pthread_self(), id, i);
        i++;

        if(i == 5)
        {
            return (void *)i;
        }
        sleep(1);
    }
}

int main(void)
{
    pthread_t thread_id[2];
    int thr_id;
    int status;
    int a = 1;
    int b = 2;

    thr_id = pthread_create(&thread_id[0], NULL, thread_function, (void *)&a);
    if(thr_id != 0)
    {
        perror("Thread creation error:");
        exit(0);
    }

    thr_id = pthread_create(&thread_id[1], NULL, thread_function, (void *)&b);
    if(thr_id != 0)
    {
        perror("Thread creation error:");
        exit(0);
    }

    pthread_join(thread_id[0], (void **)&status);
    printf("Return thread 0 %d \n", status);

    pthread_join(thread_id[1], (void **)&status);
    printf("Return thread 1 %d \n", status);

    return 0;
}
