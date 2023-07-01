//---------------------------------------------------------------------
// Arquivo      : pilha.cpp
// Conteudo     : Implementacao da classe Pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 16/04/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/pilha.hpp"

/**
 * @brief Construtor da classe Pilha
 *
 */
Pilha::Pilha() : PilhaPai()
{
    topo = -1;
}

/**
 * @brief Destrutor da classe Pilha
 *
 */
Pilha::~Pilha()
{
}

/**
 * @brief Função para empilhar um item na pilha
 *
 * @param item
 */
void Pilha::Empilha(float item)
{
    if (tamanho == MAXTAM)
        throw FullStackException();
    topo++;
    itens[topo] = item;
    tamanho++;
};

/**
 * @brief Função para desempilhar um item da pilha
 *
 * @return float
 */
float Pilha::Desempilha()
{
    float aux;
    if (tamanho == 0)
        throw EmptyStackException();
    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
    ;
};

/**
 * @brief Função para limpar a pilha
 *
 */
void Pilha::Limpa()
{
    topo = -1;
    tamanho = 0;
};
