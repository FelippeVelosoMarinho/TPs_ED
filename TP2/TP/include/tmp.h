//---------------------------------------------------------------------
// Arquivo	: tmp.h
// Conteudo	: funções para medir o tempo de usuario e do sistema
// Autor	: Felippe Veloso Marinho (felippe.veloso15@gmail.com)
// Historico	: 2023-28-03 - arquivo criado
//---------------------------------------------------------------------

#ifndef TMPH
#define TMPH
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <threads.h>

enum {NUM_ITERS = 1000000, NUM_THREADS = 16};

float diffUserTime(struct rusage *start, struct rusage *end);
float diffSystemTime(struct rusage *start, struct rusage *end);

#endif