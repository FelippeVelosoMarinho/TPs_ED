#include "../include/heapsort.hpp"

HeapSort::HeapSort()
{
}

HeapSort::~HeapSort()
{
}

void HeapSort:: heap(int *array, int esq, int dir)
{
    int i = array[esq], j = esq * 2 + 1;

    while (j <= dir)
    {
        if (j < dir)
            if (array[j] < array[j + 1])
                j = j + 1;
        if (i < array[j])
        {
            array[esq] = array[j];
            esq = j;
            j = 2 * esq + 1;
        }
        else
            j = dir + 1;
    }
    array[esq] = i;
}

void HeapSort::sort(int *array, int size)
{
    int i, aux;
    for (i = (size - 1) / 2; i >= 0; i--)
        heap(array, i, size - 1);
    for (i = size - 1; i >= 1; i--)
    {
        aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        heap(array, 0, i - 1);
    }
}

void HeapSort::print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}