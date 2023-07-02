// Arquivo      : tmp.hpp
// Conteudo     : Classes das funções temporais
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 02/07/2023 - arquivo criado
//-----

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <threads.h>

class Tmp
{
public:
    float diffUserTime(struct rusage *start, struct rusage *end);
    float diffSystemTime(struct rusage *start, struct rusage *end);
};