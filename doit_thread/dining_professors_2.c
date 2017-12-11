#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_PROFS 5
#define NUM_FORKS 5

pthread_t professors[NUM_PROFS];
int process_numbers[5] = {1, 2, 3, 4, 5};
pthread_mutex_t forks[NUM_FORKS];

void *eat(void *data);

int main(void)
{
    int i;
    int status;

    system("clear");

    for(i = 0; i < NUM_FORKS; i++)
        pthread_mutex_init(&forks[i], NULL);

    for(i = 0; i < NUM_PROFS; i++)
    {
        if(pthread_create(&professors[i], NULL, eat, (void *)&process_numbers[i]) != 0)
            perror("Failed to create thread");
    }

    for(i = 0; i < NUM_PROFS; i++)
    {
        if(pthread_join(professors[i], NULL) != 0)
            perror("Failed to terminate thread");
    }

    for(i = 0; i < NUM_FORKS; i++)
        pthread_mutex_destroy(&forks[i]);

    return 0;
}

void *eat(void *data)
{
    int number = *(int *)data;
    int i;
    int left;
    int right;
    int num_eaten = 0;

    while(1)
    {
        /* 왼쪽 포크, 오른쪽 포크가 사용할 수 있을 때까지 생각한다 */
        if(number == 0)
            left = 4;
        else left = number - 1;

        right = (number + 1) % NUM_FORKS;

        if(number == 0)
        {
            pthread_mutex_lock(&forks[right]);
            pthread_mutex_lock(&forks[left]);
        }
        else
        {
            pthread_mutex_lock(&forks[left]);
            pthread_mutex_lock(&forks[right]);
        }

        printf("철학자 %d 식사중 \n", number);
        sleep(1);
        num_eaten++;

        pthread_mutex_unlock(&forks[right]);
        pthread_mutex_unlock(&forks[left]);

        if(num_eaten == 3)
            break;
    }
}
