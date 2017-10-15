#include <stdio.h>

int sum(int start, int end)
{
    int result = 0;
    int i;

    for(i = start; i <= end; i++)
        result += i;

    return result;
}

int main(void)
{
    int number1 = 1;
    int number2 = 100;

    printf("%d \n", sum(number1, number2));

    return 0;
}
