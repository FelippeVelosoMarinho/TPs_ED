#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro
{
    TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo *TipoApontador;
typedef struct TipoNo
{
    TipoRegistro Reg;
    TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm
{
    char nomesaida[200];
    int semente;
    int numno;
    FILE *saida;
    int treesize;
    int numlevel;
} prm_t;

class Arvore
{
private:
    /* data */
public:
    Arvore(/* args */);
    ~Arvore();
    void dumpTree(TipoApontador *T, int level, prm_t *prm);
    int createTree(TipoNo **curr, int level, prm_t *prm);
    TipoNo *criaArvoreDezNos(prm_t *prm);
    void preOrder(TipoNo *node, int *order, int *count);
    void inOrder(TipoNo *node, int *order, int *count);
    void postOrder(TipoNo *node, int *order, int *count);
    int ancestral(int i, int j, TipoNo *raiz);
    
};


