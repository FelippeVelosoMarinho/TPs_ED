//---------------------------------------------------------------------
// Arquivo      : ordenadores.hpp
// Conteudo     : Classe ordenadores
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 27/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _ORDENADORES_HPP_
#define _ORDENADORES_HPP_

#include <iostream>
#include "exceptions.hpp"
#include "point.hpp"
#include "pilha.hpp"

using namespace std;

class Ordenadores
{
public:
    // Função de comparação para o MergeSort
    bool comparePoints(Point a, Point b);
    // Implementação do algoritmo de ordenação MergeSort
    void merge(Point *points, int inicio, int meio, int fim, Point p0);
    void mergeSort(Point *points, int left, int right, Point p0);
    int particiona(Pilha &pilha, int esquerda, int direita);
    int compare(Point p1, Point p2, Point p0);
    
    void Insercao(Point *v, int n);

    int orientation(Point p, Point q, Point r);
    void Insertion(Point *points, int n, Point p0);
    void Radix(Point *points, int n);
    void countingSortByDigit(Point* points, int n, int exp);
};

#endif