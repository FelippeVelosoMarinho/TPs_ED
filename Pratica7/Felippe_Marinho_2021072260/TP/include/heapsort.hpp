#include <iostream>

class HeapSort
{
public:
    HeapSort();
    ~HeapSort();
    void heap(int *array, int esq, int dir);
    void sort(int *array, int size);
    void print(int *array, int size);
};