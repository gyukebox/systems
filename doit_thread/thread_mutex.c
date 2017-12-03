#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/* Sharing data */
int num = 0;
pthread_mutex_t mutex;

void *thread_function(void *data)
{
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        // pthread_mutex_lock(&mutex);
        num++;
        printf("%s\t : %d \n", (char *)data, num);
        // pthread_mutex_unlock(&mutex);
        // sleep(1);
    }
}

int main(void)
{
    pthread_t thread[2];
    char *thread1 = "Thread A";
    char *thread2 = "Thread B";
    void *t_return = NULL;

    /* initializing mutex */
    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&thread[0], NULL, thread_function, (void *)thread1);
    pthread_create(&thread[1], NULL, thread_function, (void *)thread2);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    /* destroying mutex */
    pthread_mutex_destroy(&mutex);

    return 0;
}
