#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, child_id;
    int state;

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
        printf("Child process: \n");
        sleep(1);
        return 2;
    }
    else
    {
        printf("Parent process: wait for %d \n", pid);
        child_id = waitpid(pid, &state, 0);
        printf("Child id: %d \n", child_id);
        printf("Success to exit: %d \n", WEXITSTATUS(state));
    }


    return 0;
}
