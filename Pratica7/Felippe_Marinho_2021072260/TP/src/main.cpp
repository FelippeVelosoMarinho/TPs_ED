#include "../include/shellsort.hpp"
#include "../include/heapsort.hpp"
#include "../include/functions.hpp"
#include <iostream>

int main()
{
    Functions f;
    struct rusage start, end; // Structs para medir o tempo de execução

    srand(time(NULL));

    int size = 100;

    // Gerando um array de 1000 elementos aleatórios
    int *array = f.randomArray(size);

    ShellSort shellSort;
    HeapSort heapSort;

    getrusage(RUSAGE_SELF, &start);
    std::cout << "----------" << std::endl;
    std::cout << "HeapSort" << std::endl;
    heapSort.sort(array, size);
    getrusage(RUSAGE_SELF, &end);
    heapSort.print(array, size);
    printf("Tempo de usuário: %f\n", f.diffUserTime(&start, &end));
    printf("Tempo de sistema: %f\n", f.diffSystemTime(&start, &end));

    getrusage(RUSAGE_SELF, &start);
    std::cout << "----------" << std::endl;
    std::cout << "ShellSort" << std::endl;
    shellSort.sort(array, size);
    getrusage(RUSAGE_SELF, &end);
    shellSort.print(array, size);
    printf("Tempo de usuário: %f\n", f.diffUserTime(&start, &end));
    printf("Tempo de sistema: %f\n", f.diffSystemTime(&start, &end));

    return 0;
}