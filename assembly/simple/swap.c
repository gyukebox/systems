#include <stdio.h>

void swap(long *x, long *y)
{
    long temp = *x;
    *x = *y;
    *y = temp;
}

long main(void)
{
    long i = 10;
    long j = 20;

    swap(&i, &j);

    return 0;
}
