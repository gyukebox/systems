#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    printf("L0 \n");
    pid = fork();
    printf("L1 \n");
    pid = fork();
    printf("L2 \n");
    pid = fork();
    printf("Bye \n");


    return 0;
}
