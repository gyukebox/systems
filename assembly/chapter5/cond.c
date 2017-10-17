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

long absdiff_j(long x, long y)
{
    long result;
    long ntest = x <= y;
    if(ntest)
        goto Else;
    result = x - y;
    goto Done;
Else:
    result = y - x;
Done:
    return result;
}

long divide_by_five(long x)
{
    long result;
    if(x % 5 == 0)
        result = 1;
    else result = 0;
    return result;
}

int main(void)
{
    long l1 = 14L;
    long l2 = 18L;
    long l3 = absdiff(l1, l2);

    return 0;
}
