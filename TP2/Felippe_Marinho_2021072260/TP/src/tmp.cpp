//---------------------------------------------------------------------
// Arquivo      : tmp.cpp
// Conteudo     : Implementacao da classe tmp
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/tmp.hpp"

/**
 * @brief 
 * 
 * @param start 
 * @param end 
 * @return float 
 */
float Tmp::diffUserTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

/**
 * @brief 
 * 
 * @param start 
 * @param end 
 * @return float 
 */
float Tmp::diffSystemTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6 * (end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}