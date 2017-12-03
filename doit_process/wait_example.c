#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t child;

    child = fork();

    if(child == 0)
    {
        int i;
        for(i = 0; i < 10; i++)
        {
            printf("%d from %d \n", i, getpid());
            sleep(1);
        }
    }
    else
    {
        int i;
        for(i = 0; i < 5; i++)
        {
            printf("%d from %d \n", i, getpid());
        }
        wait(NULL);
    }

    return 0;
}
