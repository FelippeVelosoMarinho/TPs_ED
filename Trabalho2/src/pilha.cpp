//---------------------------------------------------------------------
// Arquivo      : pilha.cpp
// Conteudo     : Implementacao da classe Pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/pilha.hpp"

/**
 * @brief Função para empilhar um item na pilha
 *
 * @param item
 */
void Pilha::Empilha(Point item)
{
    if (tamanho == MAXTAM)
        throw FullStackException();
    topo++;
    itens[topo] = item;
    tamanho++;
}

/**
 * @brief Função para desempilhar um item da pilha
 *
 * @return Point
 */
Point Pilha::Desempilha()
{
    if (tamanho == 0)
        throw EmptyStackException();
    Point aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
}

/**
 * @brief Função para limpar a pilha
 *
 */
void Pilha::Limpa()
{
    topo = -1;
    tamanho = 0;
}

/**
 * @brief Função para retornar o segundo item da pilha
 *
 * @return Point
 */
Point Pilha::NextToTop(Pilha S)
{
    Point p = S.Topo();
    S.Desempilha();
    Point res = S.Topo();
    S.Empilha(p);
    return res;
}
