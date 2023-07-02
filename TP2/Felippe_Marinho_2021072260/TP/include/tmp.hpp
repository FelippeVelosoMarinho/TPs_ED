//---------------------------------------------------------------------
// Arquivo      : tmp.hpp
// Conteudo     : Classe tmp
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <threads.h>

class Tmp
{
public:
    float diffUserTime(struct rusage *start, struct rusage *end); // Retorna o tempo de usuario
    float diffSystemTime(struct rusage *start, struct rusage *end); // Retorna o tempo de sistema
};