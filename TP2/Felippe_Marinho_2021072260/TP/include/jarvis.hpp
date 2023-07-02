//---------------------------------------------------------------------
// Arquivo      : jarvis.hpp
// Conteudo     : Classe jarvis
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _JARVIS_HPP_
#define _JARVIS_HPP_
#include <cstring>
#include "point.hpp"
#include "pilha.hpp"
#include "exceptions.hpp"

using namespace std;


class Jarvis
{
public:
    // Construtor e destrutor
    Jarvis();
    ~Jarvis();

    // Metodos
    int convexHull(Point points[], int n, Point hull[], bool returnOnlyTwoPoints);
    void drawConvexHull(Point points[], int n, Point hull[], int nPoints);
    
};

#endif