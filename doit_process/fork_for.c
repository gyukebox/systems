#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("Hello from %d! \n", getpid());
        fork();
    }

    return 0;
}
