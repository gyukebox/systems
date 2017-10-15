#include <stdio.h>

long absdiff(long x, long y)
{
    long result;
    if(x > y)
        result = x - y;
    else
        result = y - x;

    return result;
}

int main(void)
{
    long l1 = 14L;
    long l2 = 18L;
    long l3 = absdiff(l1, l2);

    return 0;
}
