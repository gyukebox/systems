#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t fork_return;

    fork_return = fork();
    if(fork_return == 0)
    {
        while(1)
        {
        }
    }
    else
    {
        exit(0);
    }
}
