#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUF_SIZE 255

int main(void)
{
    char buf[BUF_SIZE] = {0};

    for( ;; )
    {
        pid_t pid, child;
        int status;

        printf("ggyu-ggyuShell:~$ ");
        scanf("%s", buf);

        pid = fork();
        
        if(pid == 0)
        {
            execlp(buf, buf, NULL); 
        }
        else
        {
            child = wait(&status);
        }
    }

    return 0;
}
