//---------------------------------------------------------------------
// Arquivo      : graham.cpp
// Conteudo     : Implementacao da classe graham
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/graham.hpp"

/**
 * @brief Construtor da classe Graham
 *
 */
Graham::Graham()
{
}

/**
 * @brief Destrutor da classe Graham
 *
 */
Graham::~Graham()
{
}

/**
 * @brief Função para encontrar o fecho convexo de um conjunto de pontos utilizando o mergesort como algoritmo de ordenação
 *
 * @param points
 * @param n
 */
void Graham::MergeConvexHull(Point points[], int n)
{
    Sort o;
    Pilha pilha;
    Point p0;

    // Find the bottommost point
    int ymin = points[0].getY(1), min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].getY(1);

        // Pick the bottom-most or choose the leftmost point in case of a tie
        if ((y < ymin) || (ymin == y && points[i].getX(1) < points[min].getX(1)))
        {
            ymin = points[i].getY(1);
            min = i;
        }
    }
    p0.swap(points[0], points[min], 1);
    p0 = Point(points[0].getX(1), points[0].getY(1)); // p0 é o ponto mais à esquerda

    o.mergeSort(points, 0, n - 1, p0, 1);
    std::cout << std::endl;
    Pilha pilhaPontos;
    for (int i = 1; i < n; i++)
    {
        pilhaPontos.Empilha(points[i], 1);
    }

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && p0.orientation(p0, points[i], points[i + 1], 1) == 0)
            i++;

        points[m] = points[i];
        m++; // Update size of modified array
    }

    if (m < 3)
        return;

    // Create an empty stack and push the first three points to it.
    pilha.Empilha(points[0], 1);
    pilha.Empilha(points[1], 1);
    pilha.Empilha(points[2], 1);

    for (int i = 3; i < m; i++)
    {
        while (pilha.GetTamanho() > 1 && p0.orientation(pilha.NextToTop(pilha, 1), pilha.Topo(), points[i], 1) != 2)
            pilha.Desempilha(1);
        pilha.Empilha(points[i], 1);
    }
}

/**
 * @brief Função para encontrar o fecho convexo de um conjunto de pontos utilizando o insertionsort como algoritmo de ordenação
 *
 * @param points
 * @param n
 */
void Graham::InsertionConvexHull(Point points[], int n)
{
    Sort o;
    Point p0;

    // Find the bottommost point
    int ymin = points[0].getY(2), min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].getY(2);

        // Pick the bottom-most or choose the leftmost point in case of a tie
        if ((y < ymin) || (ymin == y && points[i].getX(2) < points[min].getX(2)))
        {
            ymin = points[i].getY(2);
            min = i;
        }
    }

    p0.swap(points[0], points[min], 2);
    p0 = Point(points[0].getX(2), points[0].getY(2));

    // Use Insertion Sort instead of Merge Sort
    o.Insertion(points, n, p0, 2);

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && p0.orientation(p0, points[i], points[i + 1], 2) == 0)
            i++;

        points[m] = points[i];
        m++; // Update size of modified array
    }

    if (m < 3)
        return;

    Pilha pilha;

    // Create an empty stack and push the first three points to it.
    pilha.Empilha(points[0], 2);
    pilha.Empilha(points[1], 2);
    pilha.Empilha(points[2], 2);

    // Process the remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        while (pilha.GetTamanho() > 1 && p0.orientation(pilha.NextToTop(pilha, 2), pilha.Topo(), points[i], 2) != 2)
            pilha.Desempilha(2);
        pilha.Empilha(points[i], 2);
    }
}

void Graham::RadixConvexHull(Point points[], int n)
{
    Sort o;
    Point p0;
    // Encontre o ponto mais à esquerda
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].getX(3) < points[leftmost].getX(3))
        {
            leftmost = i;
        }
    }

    // Ordenar os pontos pelo ângulo polar em relação ao ponto mais à esquerda
    p0.swap(points[0], points[leftmost], 3);
    o.Radix(points + 2, n - 2);

    // Verifique se há pontos colineares e remova os pontos intermediários
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && p0.orientation(points[0], points[i], points[i + 1], 3) == 0)
        {
            i++;
        }
        points[m] = points[i];
        m++;
    }

    // Se houver menos de 3 pontos restantes, não é possível formar um fecho convexo
    if (m < 3)
    {
        return;
    }

    Pilha hull;
    hull.Empilha(points[0], 3);
    hull.Empilha(points[1], 3);
    hull.Empilha(points[2], 3);

    for (int i = 3; i < m; i++)
    {
        while (hull.GetTamanho() > 1 && p0.orientation(o.nextToTop(hull, 3), hull.Topo(), points[i], 3) != 2)
        {
            hull.Desempilha(3);
        }
        hull.Empilha(points[i], 3);
    }
}
