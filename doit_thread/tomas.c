#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *is_railroad_usable(void *name)
{
    pthread_mutex_lock(&mutex);
    printf("%s is crossing a bridge \n", (char *)name);
    sleep(1);
    printf("%s has crossed a bridge \n", (char *)name);
    pthread_mutex_unlock(&mutex);
}

int main(void)
{
    pthread_t tomas;
    pthread_t percy;
    pthread_t james;
    int tid;

    pthread_mutex_init(&mutex, NULL);

    tid = pthread_create(&tomas, NULL, is_railroad_usable, (void *)"Tomas");
    if(tid < 0)
    {
        perror("Failed to create a thread: ");
        exit(0);
    }

    tid = pthread_create(&james, NULL, is_railroad_usable, (void *)"James");
    if(tid < 0)
    {
        perror("Failed to create a thread: ");
        exit(0);
    }

    tid = pthread_create(&percy, NULL, is_railroad_usable, (void *)"Percy");
    if(tid < 0)
    {
        perror("Failed to create a thread: ");
        exit(0);
    }


    pthread_join(tomas, NULL);
    pthread_join(james, NULL);
    pthread_join(percy, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
