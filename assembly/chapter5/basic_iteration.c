#include <stdio.h>

long sum(long start, long end)
{
    long result = 0;
    long i = start;

    do {
        result += i;
        i++;
    }while(i <= end);

    return result;
}

int main(void)
{
    int number1 = 1;
    int number2 = 100;

    printf("%d \n", sum(number1, number2));

    return 0;
}
