//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao do fecho complexo
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "../include/graham.hpp"
#include "../include/jarvis.hpp"
#include "../include/sort.hpp"
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
    Point p0;
    Pilha pilha;

    struct rusage start, end; // Structs para medir o tempo de execução

    srand(time(NULL));

    int numPoints = 0;
    char *caminho;
    bool desenharPontos = false;
    bool gerarLog = false;

    if (argc > 1)
    {
        caminho = argv[1];

        for (int i = 2; i < argc; i++)
        {
            if (strcmp(argv[i], "-d") == 0)
            {
                desenharPontos = true;
            }
            else if (strcmp(argv[i], "-l") == 0)
            {
                gerarLog = true;
            }
        }
    }
    else
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo> [-d] [-l]" << std::endl;
        return 1;
    }
    if (gerarLog)
    {
        // Chame uma função para gerar os gráficos usando a memlog aqui
        std::cout << "Log gerado em ./tmp/convexHullLog.out" << std::endl;
        char *lognome = "./tmp/convexHullLog.out";
        iniciaMemLog(lognome);
        ativaMemLog();
    }

    Point *points = pilha.readPoints(caminho, numPoints);
    int n = numPoints;

    Point convexHullPoints[n];
    bool returnOnlyTwoPoints;

    // Define a fase 0 do memlog
    defineFaseMemLog(0); // Fase 0: Jarvis
    getrusage(RUSAGE_SELF, &start);
    if (p0.verifyCollinearPoints(points, n, 0))
    {
        returnOnlyTwoPoints = true; // Retorna apenas dois pontos se colineares
    }
    else
    {
        returnOnlyTwoPoints = false;
    }
    int hullSize = j.convexHull(points, n, convexHullPoints, returnOnlyTwoPoints);
    std::cout << "FECHO CONVEXO: " << std::endl;
    for (int i = hullSize - 1; i >= 0; i--)
    {
        cout << " " << convexHullPoints[i].x << " " << convexHullPoints[i].y << " " << endl;
    }
    getrusage(RUSAGE_SELF, &end);
    std::cout << std::endl;
    std::cout << "JARVIS: ";
    printf("%.3fs", f.diffUserTime(&start, &end));

    // Define a fase 1 do memlog
    defineFaseMemLog(1); // Fase 1: Graham + MergeSort
    getrusage(RUSAGE_SELF, &start);
    g.MergeConvexHull(points, n);
    getrusage(RUSAGE_SELF, &end);
    std::cout << "GRAHAM + MERGESORT: ";
    printf("%.3fs\n", f.diffUserTime(&start, &end));

    // Define a fase 2 do memlog
    defineFaseMemLog(2); // Fase 2: Graham + InsertionSort
    getrusage(RUSAGE_SELF, &start);
    g.InsertionConvexHull(points, n);
    getrusage(RUSAGE_SELF, &end);
    std::cout << "GRAHAM + INSERTIONSORT: ";
    printf("%.3fs\n", f.diffUserTime(&start, &end));

    // Define a fase 3 do memlog
    defineFaseMemLog(3); // Fase 3: Graham + RadixSort
    getrusage(RUSAGE_SELF, &start);
    std::cout << "GRAHAM + RADIX: ";
    g.RadixConvexHull(points, n);
    getrusage(RUSAGE_SELF, &end);
    printf("%.3fs\n", f.diffUserTime(&start, &end));

    if (desenharPontos)
    {
        // Pegar o numero de pontos em convexHullPoints
        int numMaxPoints = 0;
        for (int i = 0; i < n; i++)
        {
            if (convexHullPoints[i].x != 0 && convexHullPoints[i].y != 0)
            {
                numMaxPoints++;
            }
        }
        // Chame uma função para desenhar os pontos e o fecho convexo aqui

        j.drawConvexHull(convexHullPoints, numMaxPoints, pilha.readPoints(caminho, numPoints), numPoints);
    }

    if (gerarLog)
    {
        // Chame uma função para gerar os gráficos usando a memlog aqui
        std::cout << "Geração de log finalizada!" << std::endl;
        return finalizaMemLog();
    }

    return 0;
}