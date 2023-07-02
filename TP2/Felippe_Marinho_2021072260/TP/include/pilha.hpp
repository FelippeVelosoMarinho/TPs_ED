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

#define MAXTAM 100000

class Pilha
{
public:
    Pilha() { topo = -1; tamanho = 0; };
    Point *readPoints(const char *caminho, int &numPoints);
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    void Empilha(Point item, int fase);
    Point Desempilha(int fase);
    void Limpa();
    Point NextToTop(Pilha pilha, int fase); // Função que retorna o elemento abaixo do topo da pilha
    // Função que retorna o Topo da pilha
    Point Topo() { return itens[topo]; };

protected:
    int tamanho;
    int topo;
    Point itens[MAXTAM];
};

#endif