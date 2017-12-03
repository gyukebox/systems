/*
 * ku_tsort.c
 * performs sorting of integers by multi-threading
 * written by Byeong Gyu Choi
 */

#include "ku_tsort.h"

/*
 * main function to execute whole program
 * int argc : value must be 5
 * char **argv : values must be, in order,
 * 1. Total amount of number(s) to be sorted
 * 2. Total number of threads
 * 3. Name of input file
 * 4. Name of output file
 */
int main(int argc, char **argv)
{
    INDEX *indices;
    pthread_t *threads;
    FILE *fp;
    int total_numbers;
    int num_threads;
    int status;
    int i;

    if(argc != 5)
    {
        perror("Invalid Argument!");
        exit(1);
    }

    total_numbers = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    numbers = (int *)malloc(sizeof(int) * total_numbers);
    fp = fopen(argv[3], "r");
    if(fp == NULL)
    {
        perror("Failed to open file: ");
        exit(1);
    }

    /* read numbers and store into number array */
    i = 0;
    while(!feof(fp))
    {
        if(fscanf(fp, "%d", (numbers + i)) != 1)
        {
            break;
        }
        i ++;
    }

    fclose(fp);
    
    /* distribute numbers appropriately */
    indices = (INDEX *)malloc(sizeof(INDEX) *num_threads);
    for(i = 0; i < num_threads; i++)
    {
        indices[i].start_pos = total_numbers / num_threads * i;
        indices[i].end_pos = total_numbers / num_threads * (i + 1);
    }
    indices[num_threads - 1].end_pos = total_numbers;

    /* create threads */
    threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
    for(i = 0; i < num_threads; i++)
    {
        status = pthread_create(&threads[i], NULL, thread_routine, (void *)(indices + i));
        if(status != 0)
        {
            perror("Failed to create a thread: ");
            exit(1);
        }
    }

    for(i = 0; i < num_threads; i++)
    {
        status = pthread_join(threads[i], NULL);
        if(status != 0)
        {
            perror("Failed to terminate a thread");
            exit(1);
        }
    }

    /* merge sub-sorted array */
    for(i = 0; i < num_threads - 1; i++)
    {
        merge(0, indices[i + 1].start_pos, indices[i + 1].end_pos);
    }

    /* write to output file */
    fp = fopen(argv[4], "w");
    if(fp == NULL)
    {
        perror("Failed to open file: ");
        exit(1);
    }

    for(i = 0; i < total_numbers; i++)
    {
        fprintf(fp, "%d", numbers[i]);
        fputs("\n", fp);
    }

    fclose(fp);

    free(indices);
    free(threads);
    free(numbers);

    return 0;
}
/*
 * sort
 * sorts given sub-array (by merge sort)
 * param int left : left boundary of array(included in sorting)
 * param int right : right boundary of array(excluded in sorting)
 * return : void
 */
void sort(int left, int right)
{
    if((right - left) < 2)
        return;

    sort(left, left + (right - left) / 2);
    sort(left + (right - left) / 2, right);

    merge(left, left + (right - left) / 2,  right);
}
/*
 * merge
 * merges sub-sorted array
 * param int first_start : start index of first section
 * param int second_start : start index of second section, which is equal to end of first section
 * param int second_end : end index of second section
 * return : void
 */
void merge(int first_start, int second_start, int second_end)
{
    int i = first_start;
    int j = second_start;
    int index = first_start;

    /* making a copy */
    int *copy = (int *)malloc(sizeof(int) * second_end);
    memcpy(copy, numbers, sizeof(int) * second_end);

    while(1)
    {
        if(i >= second_start)
        {
            memmove(&numbers[index], &copy[j], sizeof(int) * (second_end - j));
            break;
        }
        if(j >= second_end)
        {
            memmove(&numbers[index], &copy[i], sizeof(int) * (second_start - i));
            break;
        }
        if(copy[i] > copy[j])
        {
            numbers[index] = copy[j];
            index++;
            j++;
        }
        else
        {
            numbers[index] = copy[i];
            index++;
            i++;
        }
    }

    free(copy);
}
/*
 * thread_routine
 * function that will be run in threads
 * this function will sub-sort the array
 * param void *data : any data that will be sent into thread
 * return : void
 */
void *thread_routine(void *data)
{
    INDEX *index = (INDEX *)data;
    sort(index->start_pos, index->end_pos);
}
