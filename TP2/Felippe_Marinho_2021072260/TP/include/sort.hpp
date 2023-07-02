//---------------------------------------------------------------------
// Arquivo      : sort.hpp
// Conteudo     : Classe sort
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 27/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _SORT_HPP_
#define _SORT_HPP_

#include <iostream>
#include "exceptions.hpp"
#include "point.hpp"
#include "pilha.hpp"

using namespace std;

class Sort
{
public:
    // Função de comparação para o MergeSort
    bool comparePoints(Point a, Point b, int fase);
    // Implementação do algoritmo de ordenação MergeSort
    void merge(Point *points, int inicio, int meio, int fim, Point p0, int fase);
    void mergeSort(Point *points, int left, int right, Point p0, int fase);
    
    int compare(Point p1, Point p2, Point p0, int fase);
    Point nextToTop(Pilha &stk, int fase);
    int findMax(Point array[], int size);

    void Insertion(Point *points, int n, Point p0, int fase);
    void Radix(Point *points, int n);
    void countingSortByDigit(Point* points, int n, int exp);
};

#endif