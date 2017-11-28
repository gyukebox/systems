#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    printf("Before fork: %d \n", getpid());

    pid = fork();

    if(pid == 0)
    {
        printf("Child process id: %d \n", getpid());
        printf("pid :: %d \n", pid);
    }
    else if(pid > 0)
    {
        printf("Parent process id: %d \n", getpid());
        printf("pid :: %d \n", pid);
    }
    else
    {
        printf("Fork failed: %d \n", pid);
    }


    return 0;
}
