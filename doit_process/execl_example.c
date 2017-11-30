#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Hello world! \n");
    execl("/usr/bin/git", "git clone", "https://github.com/gyukebox/depromeetmining", NULL);
    printf("Goodbye world! \n");

    return 0;
}

