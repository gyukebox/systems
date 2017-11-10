#include <stdio.h>

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(void)
{
    int i = 10;
    int j = 20;

    printf("i = %d, j = %d \n", i, j);
    swap(i, j);
    printf("i = %d, j = %d \n", i, j);

    return 0;
}
