//---------------------------------------------------------------------
// Arquivo      : graham.hpp
// Conteudo     : Classe graham
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _GRAHAM_HPP_
#define _GRAHAM_HPP_

#include "point.hpp"
#include "pilha.hpp"
#include "exceptions.hpp"
#include "ordenadores.hpp"
#include <iostream>
#include <algorithm>

using namespace std;


class Graham
{
public:
    // Construtor e destrutor
    Graham();
    ~Graham();

    int orientation(Point p, Point q, Point r);

    // Metodos
    void MergeConvexHull(Point points[], int n);
    void InsertionConvexHull(Point points[], int n);
    void RadixConvexHull(Point points[], int n);
    
};

#endif