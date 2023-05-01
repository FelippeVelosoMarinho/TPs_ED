#include "../include/pilha.hpp"

Pilha::Pilha() : PilhaPai()
{
    topo = -1;
}

void Pilha::Empilha(float item)
{
    if (tamanho == MAXTAM)
        throw "A pilha está cheia!";
    topo++;
    itens[topo] = item;
    tamanho++;
};

float Pilha::Desempilha()
{
    float aux;
    if (tamanho == 0)
        throw "A pilha está vazia!";
    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
    ;
};

void Pilha::Limpa()
{
    topo = -1;
    tamanho = 0;
};
