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
    Ordenadores o;
    Pilha pilha;
    Point p0;

    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or choose the leftmost point in case of a tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    // Place the bottom-most point at the first position
    p0.swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has a larger polar angle (in counterclockwise direction) than p1
    p0 = points[0];

    o.mergeSort(points, 0, n - 1, p0);
    std::cout << std::endl;
    Pilha pilhaPontos;
    for (int i = 1; i < n; i++)
    {
        pilhaPontos.Empilha(points[i]);
    }

    // If two or more points make the same angle with p0,
    // remove all but the one that is farthest from p0
    // Remember that, in the above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have the same angle.
    int m = 1; // Initialize size of modified array
    for (int i = 1; i < n; i++)
    {
        // Keep removing i while the angle of i and i+1 is the same
        // with respect to p0
        while (i < n - 1 && p0.orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++; // Update size of modified array
    }

    // If the modified array of points has less than 3 points,
    // the convex hull is not possible
    if (m < 3)
        return;

    // Create an empty stack and push the first three points to it.
    pilha.Empilha(points[0]);
    pilha.Empilha(points[1]);
    pilha.Empilha(points[2]);

    // Process the remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing the top while the angle formed by
        // the points next-to-top, top, and points[i] makes
        // a non-left turn
        while (pilha.GetTamanho() > 1 && p0.orientation(pilha.NextToTop(pilha), pilha.Topo(), points[i]) != 2)
            pilha.Desempilha();
        pilha.Empilha(points[i]);
    }

    // Now the stack has the output points, print the contents of the stack
    while (!pilha.Vazia())
    {
        Point p = pilha.Topo();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        pilha.Desempilha();
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
    Ordenadores o;
    Point p0;

    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or choose the leftmost point in case of a tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    // Place the bottom-most point at the first position
    p0.swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has a larger polar angle (in counterclockwise direction) than p1
    p0 = points[0];

    // Use Insertion Sort instead of Merge Sort
    o.Insertion(points, n, p0);

    // If two or more points make the same angle with p0,
    // remove all but the one that is farthest from p0
    // Remember that, in the above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have the same angle.
    int m = 1; // Initialize size of modified array
    for (int i = 1; i < n; i++)
    {
        // Keep removing i while the angle of i and i+1 is the same
        // with respect to p0
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++; // Update size of modified array
    }

    // If the modified array of points has less than 3 points,
    // the convex hull is not possible
    if (m < 3)
        return;

    Pilha pilha;

    // Create an empty stack and push the first three points to it.
    pilha.Empilha(points[0]);
    pilha.Empilha(points[1]);
    pilha.Empilha(points[2]);

    // Process the remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing the top while the angle formed by
        // the points next-to-top, top, and points[i] makes
        // a non-left turn
        while (pilha.GetTamanho() > 1 && orientation(pilha.NextToTop(pilha), pilha.Topo(), points[i]) != 2)
            pilha.Desempilha();
        pilha.Empilha(points[i]);
    }

    // Now the stack has the output points, print the contents of the stack
    while (!pilha.Vazia())
    {
        Point p = pilha.Topo();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        pilha.Desempilha();
    }
}

int Graham::orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // Collinear
    else if (val > 0)
        return 1; // Clockwise
    else
        return 2; // Counterclockwise
}

void Graham::RadixConvexHull(Point points[], int n)
{
    Ordenadores o;
    Pilha pilha;
    Point p0;

    // Encontre o ponto mais baixo
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Escolha o ponto mais baixo ou escolha o ponto mais à esquerda em caso de empate
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    // Coloque o ponto mais baixo na primeira posição
    p0.swap(points[0], points[min]);

    // Ordene os pontos pelo componente x usando Radix Sort
    o.Radix(points, n);

    // Remova os pontos com a mesma coordenada x mantendo apenas o ponto mais distante de p0
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && p0.orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    // Se o array modificado de pontos tiver menos de 3 pontos, o Convex Hull não é possível
    if (m < 3)
        return;

    // Crie uma pilha vazia e empilhe os três primeiros pontos
    pilha.Empilha(points[0]);
    pilha.Empilha(points[1]);
    pilha.Empilha(points[2]);

    // Processar os pontos restantes
    for (int i = 3; i < m; i++)
    {
        while (pilha.GetTamanho() > 1 && p0.orientation(pilha.NextToTop(pilha), pilha.Topo(), points[i]) != 2)
            pilha.Desempilha();
        pilha.Empilha(points[i]);
    }

    // A pilha agora contém os pontos do Convex Hull, imprimir os pontos na pilha
    while (!pilha.Vazia())
    {
        Point p = pilha.Topo();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        pilha.Desempilha();
    }
}
