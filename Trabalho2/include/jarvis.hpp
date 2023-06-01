//---------------------------------------------------------------------
// Arquivo      : jarvis.hpp
// Conteudo     : Classe jarvis
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _JARVIS_HPP_
#define _JARVIS_HPP_

#include "point.hpp"
#include "exceptions.hpp"

using namespace std;


class Jarvis
{
public:
    // Construtor e destrutor
    Jarvis();
    ~Jarvis();

    // Metodos
    int convexHull(Point points[], int n, Point hull[]);
    
};

#endif