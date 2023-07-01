//---------------------------------------------------------------------
// Arquivo      : tmp.c
// Conteudo     : funções para medir o tempo de usuario e do sistema
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 2023-28-03 - arquivo criado
//---------------------------------------------------------------------

#include "../include/tmp.h"

float diffUserTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float diffSystemTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}