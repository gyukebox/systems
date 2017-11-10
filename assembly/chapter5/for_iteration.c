#include <stdio.h>

int main(void)
{
    int i;
    int start = 14;
    int end = 28;
    int sum = 0;

    for(i = start; i <= end; i++)
    {
        sum += i;
    }

    return sum;
}
