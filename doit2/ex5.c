#include <stdio.h>

int max(int x, int y)
{
    if(x > y)
        return x;
    else return y;
}

int main()
{
    int x = 4;
    int y = 6;
    int ret = 0;
    ret = max(x, y);

    return 0;
}
