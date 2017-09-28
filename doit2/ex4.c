#include <stdio.h>

int main()
{
    unsigned int ret;

    __asm__ __volatile__("rdtsc": "=A"(ret));
    printf("clock time: %d \n", ret);

    return 0;
}
