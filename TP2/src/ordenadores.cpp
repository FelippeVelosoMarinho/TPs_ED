//---------------------------------------------------------------------
// Arquivo      : ordenadores.cpp
// Conteudo     : Implementacao do algoritmo ordenadores
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 27/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/ordenadores.hpp"

// Função para verificar a orientação de três pontos (p, q, r)
int Ordenadores::orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // sentido horário ou anti-horário
}

/**
 * @brief Função de comparação para o MergeSort
 *
 * @param a
 * @param b
 * @return true
 * @return false
 */
bool Ordenadores::comparePoints(Point p1, Point p2)
{
    // Encontrar a orientação dos pontos em relação ao ponto de referência
    int o = orientation(Point(0, 0), p1, p2);

    if (o == 0)
    {
        // Se os pontos são colineares, retorna o mais distante
        return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
    }

    return (o == 2); // Retorna verdadeiro se p2 é mais à esquerda do que p1
}

int Ordenadores::compare(Point p1, Point p2, Point p0)
{
    int o = orientation(p0, p1, p2);
    if (o == 0)
    {
        // If both points are collinear, compare based on distance from p0
        int distSq1 = p0.distSquare(p1);
        int distSq2 = p0.distSquare(p2);
        if (distSq1 < distSq2)
            return -1;
        else if (distSq1 > distSq2)
            return 1;
        else
            return 0;
    }
    else if (o == 2)
    {
        // If p1 is counterclockwise (left) to p2, return -1
        return -1;
    }
    else
    {
        // If p1 is clockwise (right) to p2, return 1
        return 1;
    }
}

// Função para mesclar duas sublistas ordenadas em um único vetor
void Ordenadores::merge(Point *points, int inicio, int meio, int fim, Point p0)
{
    int p1 = meio - inicio + 1;
    int p2 = fim - meio;

    // Indices dos subarrays que vão ser temporários
    int indexStart = 0;
    int indexEnd = 0;

    // Indice do array points que vai ser a união dos subarrays
    int indexMerged = inicio;

    // Arrays temporários de subconjunto de pontos
    Point *pointStart = new Point[p1];
    Point *pointEnd = new Point[p2];

    for (int i = 0; i < p1; i++)
        pointStart[i] = points[inicio + i];

    for (int j = 0; j < p2; j++)
        pointEnd[j] = points[meio + 1 + j];

    // Compara os pontos com base nas coordenadas X e Y
    while (indexStart < p1 && indexEnd < p2)
    {
        if (pointStart[indexStart].getY() < pointEnd[indexEnd].getY()) // Coordenada y do primeiro ponto é menor que o segundo
        {
            points[indexMerged] = pointStart[indexStart];
            indexStart++;
        }

        else if (pointStart[indexStart].getY() == pointEnd[indexEnd].getY()) // Coordenadas y dos pontos são iguais
        {
            if (pointStart[indexStart].getX() < pointEnd[indexEnd].getX()) // Analisa a coordenada x no caso dos pontos y serem iguais
            {
                points[indexMerged] = pointStart[indexStart];
                indexStart++;
            }
            else
            {
                points[indexMerged] = pointEnd[indexEnd];
                indexEnd++;
            }
        }
        else // Coordenada y do primeiro ponto é maior que do segundo
        {
            points[indexMerged] = pointEnd[indexEnd];
            indexEnd++;
        }
        indexMerged++;
    }

    // Copia os elementos do subconjunto de pontos do inicio se ainda houver algum
    while (indexStart < p1)
    {
        points[indexMerged] = pointStart[indexStart];
        indexStart++;
        indexMerged++;
    }

    // Copia os elementos do subconjunto de pontos do final se ainda houver algum
    while (indexEnd < p2)
    {
        points[indexMerged] = pointEnd[indexEnd];
        indexEnd++;
        indexMerged++;
    }

    // Ordenar os pontos em relação ao ponto inicial computando o ângulo entre os pontos
    for (int i = inicio + 1; i <= fim; i++)
    {
        for (int j = i + 1; j <= fim; j++)
        {
            double firstAngle = points[inicio].computeAngle(points[i]);
            double secondAngle = points[inicio].computeAngle(points[j]);

            if (firstAngle > secondAngle)
            {
                Point aux = points[i];
                points[i] = points[j];
                points[j] = aux;
            }
        }
    }

    delete[] pointStart;
    delete[] pointEnd;
}

/**
 * @brief Implementação do algoritmo de ordenação MergeSort
 *
 * @param pilha
 */
void Ordenadores::mergeSort(Point *points, int inicio, int fim, Point p0)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(points, inicio, meio, p0);
        mergeSort(points, meio + 1, fim, p0);

        merge(points, inicio, meio, fim, p0);
    }
}

void Ordenadores::Insertion(Point *points, int n, Point p0)
{
    for (int i = 1; i < n; i++)
    {
        Point key = points[i];
        int j = i - 1;

        // Move the points whose x-coordinate is greater than the key one position ahead
        while (j >= 0 && compare(points[j], key, p0) > 0)
        {
            points[j + 1] = points[j];
            j--;
        }

        // Insert the key at the correct position
        points[j + 1] = key;
    }
}

void Ordenadores::Radix(Point* points, int n) {
    // Encontre o maior valor de x para determinar o número de dígitos
    int max_x = points[0].x;
    for (int i = 1; i < n; i++) {
        if (points[i].x > max_x) {
            max_x = points[i].x;
        }
    }

    // Realize a ordenação pelo componente x usando o Radix Sort
    for (int exp = 1; max_x / exp > 0; exp *= 10) {
        countingSortByDigit(points, n, exp);
    }
}

void Ordenadores::countingSortByDigit(Point* points, int n, int exp) {
    const int k = 10;  // Intervalo de dígitos de 0 a 9
    Point* output = new Point[n];
    int count[k] = {0};

    // Contagem da frequência de cada dígito
    for (int i = 0; i < n; i++) {
        int digit = (points[i].x / exp) % 10;
        count[digit]++;
    }

    // Ajuste de contagem para obter as posições corretas dos dígitos
    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    // Construção do array de saída ordenado pelos dígitos
    for (int i = n - 1; i >= 0; i--) {
        int digit = (points[i].x / exp) % 10;
        output[count[digit] - 1] = points[i];
        count[digit]--;
    }

    // Copiar o array ordenado de volta para o array original
    for (int i = 0; i < n; i++) {
        points[i] = output[i];
    }

    delete[] output;
}