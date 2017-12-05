#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define NAME_POSIX "/my_mq"

int *number;
void sort(int start, int end);
void merge(int start, int mid, int end);

