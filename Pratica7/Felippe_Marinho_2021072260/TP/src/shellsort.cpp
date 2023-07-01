#include "../include/shellsort.hpp"

ShellSort::ShellSort()
{
}

ShellSort::~ShellSort()
{
}

void ShellSort::sort(int *v, int n)
{
    /*int i, j, k, temp;
    for (i = size / 2; i > 0; i = i / 2)
    {
        for (j = i; j < size; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (array[k + i] >= array[k])
                    break;
                else
                {
                    temp = array[k];
                    array[k] = array[k + i];
                    array[k + i] = temp;
                }
            }
        }
    }*/

    int i, j, h, aux;

    for (h = 1; h < n; h = 3 * h + 1)
        ; /* h inicial . */

    do
    {
        h = (h - 1) / 3; /* atualiza h. */
        for (i = h; i < n; i++)
        {
            aux = v[i];
            j = i;
            /* Comparações entre elementos com distância h: */
            while (v[j - h] > aux)
            {
                v[j] = v[j - h];
                j -= h;
                if (j < h)
                    break;
            }
            v[j] = aux;
        }
    } while (h != 1);
}

void ShellSort::print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
