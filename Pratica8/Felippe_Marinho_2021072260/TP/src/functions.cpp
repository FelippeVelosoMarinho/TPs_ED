#include "../include/functions.hpp"

float Functions::diffUserTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float Functions::diffSystemTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}

int *Functions::randomArray(int size)
{
    int *array = new int[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }
    return array;
}