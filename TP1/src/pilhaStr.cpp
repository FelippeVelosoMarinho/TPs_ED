//---------------------------------------------------------------------
// Arquivo      : pilhaStr.cpp
// Conteudo     : Implementacao da classe PilhaStr
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 08/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/pilhaStr.hpp"

/**
 * @brief Construtor da classe Pilha
 *
 */
PilhaStr::PilhaStr() : PilhaPaiStr()
{
    topo = -1;
}

/**
 * @brief Destrutor da classe Pilha
 *
 */
PilhaStr::~PilhaStr()
{
}

/**
 * @brief Função para empilhar um item na pilha
 *
 * @param item
 */
void PilhaStr::EmpilhaStr(char *item)
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
 * @return *char
 */
char *PilhaStr::DesempilhaStr()
{
    char *aux;
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
void PilhaStr::LimpaStr()
{
    topo = -1;
    tamanho = 0;
};
