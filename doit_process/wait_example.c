#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid, child_id;
    int data;
    int state;

    data = 10;
    pid = fork();

    if(pid < 0)
    {
        printf("Failed to fork \n");
    }
    else
    {
        printf("Success to fork: %d \n", pid);
    }

    if(pid == 0)
    {
        data += 10;
    }
    else
    {
        data -= 10;
        child_id = wait(&state);

        printf("Child pid: %d \n", child_id);
    }

    printf("\tdata: %d \n", data);

    return 0;
}
