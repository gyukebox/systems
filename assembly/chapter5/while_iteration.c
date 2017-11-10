#include <stdio.h>

int main(void)
{
    int sum = 0;
    int i = 0;

    while(i < 100)
    {
        sum += i+1;
        i++;
    }

    return sum;
}
