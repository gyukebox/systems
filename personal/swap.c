#include <stdio.h>

void swap(long *xp, long *yp) {
    long t0 = *xp;
    long t1 = *yp;
    *xp = t1;
    *yp = t0;
}

int main(int argc, char **argv) {
    long i = 20L;
    long j = 40L;

    swap(&i, &j);

    return 0;
}
