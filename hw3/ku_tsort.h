/*
 * ku_tsort.h
 * header file for ku_tsort.c
 * written by Byeong Gyu Choi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

typedef struct _INDEXINFO
{
    int start_pos;
    int end_pos;
}INDEX;

int *numbers;

void sort(int left, int right);
void merge(int first_start, int second_start, int second_end);
void *thread_routine(void *data);
