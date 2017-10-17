#include <stdio.h>

void swap(long *x, long *y)
{
    long temp = *x;
    long temp2 = *y;
    *x = temp2;
    *y = temp;
}

void int_swap(int *x, int *y)
{
    int t1 = *x;
    int t2 = *y;
    *x = t2;
    *y = t1;
}

void short_swap(short *x, short *y)
{
    short temp = *x;
    short temp2 = *y;
    *x = temp2;
    *y = temp;
}

void char_swap(char *x, char *y)
{
    char temp = *x;
    char temp2 = *y;
    *x = temp2;
    *y = temp;
}

int main(void)
{
    return 0;
}
