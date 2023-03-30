//---------------------------------------------------------------------
// Arquivo      : fat.c
// Conteudo     : programa de avaliação de fat
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 2023-28-03 - arquivo criado
//---------------------------------------------------------------------

#include "../include/fat.h"

int fat_iterativo(int n)
{
    int i, fat = 1;
    for (i = 1; i <= n; i++)
    {
        fat = fat * i;
    }
    //printf("%d", fat);
    return fat;
}

int fat_recursivo(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        //printf("%d", n * fat_recursivo(n - 1));
        return n * fat_recursivo(n - 1);
    }
}