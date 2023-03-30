//---------------------------------------------------------------------
// Arquivo      : main.c
// Conteudo     : programa de avaliacao do TAD FAT e FIBONACCI
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 2023-03-21 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>

#include "../include/fat.h"
#include "../include/fibonacci.h"
#include "../include/tmp.h"

static int opt;
int num;

void parseArgs(int argc, char **argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty
{
    int aux;
    num = -1;
    opt = -1;

    while ((aux = getopt(argc, argv, "abn:h")) != EOF) // flags a, b,  n requerem um argumento e h nao requer argumento
    {
        switch (aux)
        {
        case 'a':
            opt = opFat;
            break;
        case 'b':
            opt = opFib;
            break;
        case 'n':
            if (optarg != NULL)
                num = atoi(optarg);
            break;
        case 'h':
            printf("Ajuda: \n");
            printf("No makefile é passado os seguintes argumentos para o programa: \n");
            printf("-a -> escolhe a operação fatorial \n");
            printf("-b -> escolhe a operação fibonacci \n");
            printf("-n -> escolhe o número que vai ser calculado o fatorial ou fibonacci \n");
            printf("Exemplo: -a -n 5 \n");

            break;
        default:
            fprintf(stderr, "Opção inválida ou ausente: %c \n", optopt); //para pegarmos a saída de erro
            break;
        }
    }
}

int main(int argc, char **argv)
// Descricao: programa principal para execucao de operacoes de matrizes
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
    struct rusage start, end;
    parseArgs(argc, argv); //chamando a função que permite ler da linha de comando

    switch (opt)
    {
    case opFat:
        getrusage(RUSAGE_SELF, &start); // o inteiro RUSAGE_SELF é definido em <sys/resource.h>
        fat_iterativo(num);
        getrusage(RUSAGE_SELF, &end);
        printf("\nStatus Fatorial Iterativo\n");
        printf("Tempo de usuario (CPU): %f seg, \n", diffUserTime(&start, &end));
        printf("Tempo de sistema: %f\n", diffSystemTime(&start, &end));

        getrusage(RUSAGE_SELF, &start);
        fat_recursivo(num);
        getrusage(RUSAGE_SELF, &end);
        printf("\nStatus Fatorial Recursivo\n");
        printf("Tempo de usuario (CPU): %f\n", diffUserTime(&start, &end));
        printf("Tempo de sistema: %f\n", diffSystemTime(&start, &end));
        
        break;
    case opFib:
        getrusage(RUSAGE_SELF, &start);
        fib_iterativo(num);
        getrusage(RUSAGE_SELF, &end);
        printf("\nStatus Fibonacci Iterativo\n");
        printf("Tempo de usuario (CPU): %f seg, \n", diffUserTime(&start, &end));
        printf("Tempo de sistema: %f\n", diffSystemTime(&start, &end));

        getrusage(RUSAGE_SELF, &start);
        fib_recursivo(num);
        getrusage(RUSAGE_SELF, &end);
        printf("\nStatus Fibonacci Recursivo\n");
        printf("Tempo de usuario (CPU): %f seg, \n", diffUserTime(&start, &end));
        printf("Tempo de sistema: %f\n", diffSystemTime(&start, &end));
        break;
    default:
        break;
    }
    return 0;
}
