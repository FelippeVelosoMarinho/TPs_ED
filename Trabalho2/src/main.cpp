//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao do fecho complexo
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "../include/graham.hpp"
#include "../include/jarvis.hpp"
#include "../include/ordenadores.hpp"
#include "../include/tmp.hpp"

/**
 * @brief Função principal do programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    Graham g;
    Jarvis j;
    Tmp f;

    struct rusage start, end; // Structs para medir o tempo de execução

    srand(time(NULL));

    /*char *caminho;
    if (argc > 1)
    {
        caminho = argv[1];
    }
    else
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo>" << std::endl;
        return 1;
    }*/

    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    // Point points[] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}, {17, 17}, {18, 18}, {19, 19}};

    int n = sizeof(points) / sizeof(points[0]);
    getrusage(RUSAGE_SELF, &start);
    printf("FECHO CONVEXO: ");
    g.MergeConvexHull(points, n);
    getrusage(RUSAGE_SELF, &end);
    // printf("Tempo de usuário: %fs\n", f.diffUserTime(&start, &end));
    // printf("Tempo de sistema: %fs\n", f.diffSystemTime(&start, &end));

    std::cout << std::endl;
    std::cout << "GRAHAM + MERGESORT: ";
    printf("%fs\n", f.diffUserTime(&start, &end));

    getrusage(RUSAGE_SELF, &start);
    g.InsertionConvexHull(points, n);
    getrusage(RUSAGE_SELF, &end);
    std::cout << "GRAHAM + INSERTIONSORT: ";
    printf("%fs\n", f.diffUserTime(&start, &end));
    
    getrusage(RUSAGE_SELF, &start);
    std::cout << "GRAHAM + RADIX: ";
    g.RadixConvexHull(points, n);
    getrusage(RUSAGE_SELF, &end);
    printf("%fs\n", f.diffUserTime(&start, &end));

    Point convexHullPoints[n];
    /*int hullSize = j.convexHull(points, n, convexHullPoints);

    for (int i = hullSize - 1; i >= 0; i--)
    {
        cout << " " << convexHullPoints[i].x << ", " << convexHullPoints[i].y << " " << endl;
    }*/
    getrusage(RUSAGE_SELF, &end);
    std::cout << "JARVIS: ";
    printf("%fs\n", f.diffUserTime(&start, &end));

    return 0;
}