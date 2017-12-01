/*
 * ku_psort.h
 * header file for ku_psort.c
 * written by Byeong Gyu Choi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mqueue.h>
#include <errno.h>
#include <fcntl.h>

void sort(int left, int right);
void merge(int first_start, int second_start, int second_end);

#define NAME_POSIX "/my_mq"
