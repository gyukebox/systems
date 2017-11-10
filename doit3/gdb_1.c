#include <stdio.h>

static void do_swap(int *lhs, int *rhs, int *tmp)
{
    tmp = 0;
    *tmp = *lhs;
    *lhs = *rhs;
    *rhs = *tmp;
}

void swap(int *lhs, int *rhs)
{
    int t;
    do_swap(lhs, rhs, &t);
}

int main(void)
{
    int i = 0;
    int j = 1;

    printf("i = %d, j = %d \n", i, j);
    swap(&i, &j);
    printf("i = %d, j = %d \n", i, j);

    return 0;
}
