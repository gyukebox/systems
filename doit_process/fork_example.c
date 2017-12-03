#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t child;

    printf("Before fork: %d \n", getpid());

    child = fork();

    if(child == 0)
    {
        printf("Child process id: %d \n", getpid());
        printf("pid :: %d \n", child);
    }
    else if(child > 0)
    {
        printf("Parent process id: %d \n", getpid());
        printf("pid :: %d \n", child);
    }
    else
    {
        printf("Fork failed: %d \n", child);
    }

    printf("Hello! \n");

    return 0;
}
