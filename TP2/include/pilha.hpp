//---------------------------------------------------------------------
// Arquivo      : pilha.hpp
// Conteudo     : Classe pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _PILHA_HPP_
#define _PILHA_HPP_

#include <iostream>
#include "point.hpp"
#include "exceptions.hpp"

#define MAXTAM 1000

class Pilha
{
public:
    Pilha() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    void Empilha(Point item);
    Point Desempilha();
    void Limpa();
    Point NextToTop(Pilha pilha);
    // Função que retorna o Topo da pilha
    Point Topo() { return itens[topo]; };

protected:
    int tamanho;
    int topo;
    Point itens[MAXTAM];
};

#endif