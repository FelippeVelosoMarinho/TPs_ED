//---------------------------------------------------------------------
// Arquivo      : point.hpp
// Conteudo     : Classe point
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <iostream>
#include <cmath>
#include <algorithm>
#include "exceptions.hpp"

using namespace std;

class Point
{

public:
    Point();
    Point(int x, int y);
    ~Point();
    int orientation(Point p, Point q, Point r);
    int distSq(Point p1, Point p2);
    void drawPoint(int x, int y);
    int compare(const void *vp1, const void *vp2);
    void swap(Point &p1, Point &p2);
    double computeAngle(Point p);   
    int getX();
    int getY();
    int x;
    int y;
    static Point p0; // Declarando p0 como uma variável estática
        // Retorna o quadrado da distância entre este ponto e outro ponto p
    int distSquare(Point p);
};

#endif