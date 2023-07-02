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
#include "memlog.hpp"
#include "exceptions.hpp"

using namespace std;

class Point
{

public:
    Point();
    Point(int x, int y);
    ~Point();

    // Coordenadas do ponto
    int x;
    int y;

    // Funcoes para retornar as coordenadas do ponto
    int getX(int fase);
    int getY(int fase);

    // Funcoes para setar as coordenadas do ponto
    void setX(int x, int fase);
    void setY(int y, int fase);

    static Point p0; // Declarando p0 como uma variável estática

    // funcoes auxiliares
    int orientation(Point p, Point q, Point r, int fase); // Retorna a orientacao de um conjunto de pontos
    int getOrientation(const Point &p, const Point &q, const Point &r, int fase); // Retorna a orientacao de um conjunto de pontos com parametros diferentes
    int distSq(Point p1, Point p2, int fase); // Retorna o quadrado da distância entre dois pontos
    void swap(Point &p1, Point &p2, int fase); // Troca os valores de dois pontos
    double computeAngle(Point p, int fase); // Retorna o angulo entre este ponto e o ponto p
    int distSquare(Point p, int fase); // Retorna o quadrado da distância entre este ponto e outro ponto p

    // Funcoes usadas nas funcoes de ordenacao
    int verifyCollinearPoints(Point *points, int n, int fase); // Verifica se existem pontos colineares
    bool isPointInHull(const Point &point, Point hull[], int n, int fase); // Verifica se um ponto está dentro do fecho convexo
};

#endif