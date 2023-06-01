//---------------------------------------------------------------------
// Arquivo      : jarvis.cpp
// Conteudo     : Classe jarvis
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/jarvis.hpp"

/**
 * @brief Construtor da classe Jarvis
 *
 */
Jarvis::Jarvis()
{
}

/**
 * @brief Destrutor da classe Jarvis
 *
 */
Jarvis::~Jarvis()
{
}

/**
 * @brief Função para encontrar o fecho convexo de um conjunto de pontos
 *
 * @param points
 * @param n
 * @param hull
 * @return int
 */
// Função principal que implementa o algoritmo de Marcha de Jarvis
int Jarvis::convexHull(Point points[], int n, Point hull[])
{
    // Verifique se há pelo menos 3 pontos
    if (n < 3)
        return 0;

    // Encontre o ponto mais à esquerda
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    int p = leftmost, q;
    int idx = 0;

    do
    {
        hull[idx++] = points[p];
        q = (p + 1) % n;

        for (int i = 0; i < n; i++)
        {
            if (points[i].orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != leftmost);

    return idx;
}