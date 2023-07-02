//---------------------------------------------------------------------
// Arquivo      : jarvis.cpp
// Conteudo     : Classe jarvis
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include <graphics.h>

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
int Jarvis::convexHull(Point points[], int n, Point hull[], bool returnOnlyTwoPoints)
{
    Point p0(points[0].getX(0), points[0].getY(0));
    // Verifique se há pelo menos 3 pontos
    if (n < 3)
        return 0;

    // Verifica se o tamanho do array é válido
    if (n < 2)
        throw PointsArrayInvalidSizeException();

    // Se no array de pontos só tiver pontos colineares, o fecho convexo é a linha que liga o primeiro e o último ponto
    if (p0.verifyCollinearPoints(points, n, 0))
    {
        if (returnOnlyTwoPoints)
        {
            hull[0] = points[0];
            hull[1] = points[n - 1];
            return 2;
        }
    }

    // Encontre o ponto mais à esquerda
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {

        if (points[i].getX(0) < points[leftmost].getX(0))
            leftmost = i;
    }

    int p = leftmost, q;
    int idx = 0;

    do
    {
        hull[idx++] = Point(points[p].getX(0), points[p].getY(0));
        q = (p + 1) % n;

        for (int i = 0; i < n; i++)
        {
            if (points[i].orientation(points[p], points[i], points[q], 0) == 2)
                q = i;
        }

        p = q;

    } while (p != leftmost);

    return idx;
}

/**
 * @brief Função para desenhar o fecho convexo de um conjunto de pontos
 *
 * @param points
 * @param n
 * @param hull
 */
void Jarvis::drawConvexHull(Point points[], int n, Point hull[], int nPoints)
{
    Point p0;
    int xMax = 530, yMax = 480;

    // Encontre o ponto com as maiores coordenadas para determinar a escala de proporção
    int xMaxPoint = points[0].x;
    int yMaxPoint = points[0].y;

    for (int i = 1; i < n; i++)
    {
        if (points[i].x > xMaxPoint)
            xMaxPoint = points[i].x;
        if (points[i].y > yMaxPoint)
            yMaxPoint = points[i].y;
    }

    // Calcule a escala de proporção para redimensionar os pontos
    double xScale = static_cast<double>(xMaxPoint * 100) / xMax;
    double yScale = static_cast<double>(yMaxPoint * 100) / yMax;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(BLUE);
    cleardevice();
    // settextstyle(9, 0, 2);
    char *msg = "Pixar Animation Studios®";
    outtextxy(450, 440, msg);

    setcolor(YELLOW);

    std::cout << "Desenhando os pontos do fecho convexo..." << std::endl;
    // Encontre o ponto mais à esquerda para começar a desenhar
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    // Desenhe os pontos que estão fora do fecho convexo
    for (int i = 0; i < n; i++)
    {
        Point current = points[i];

        // Redimensione os pontos que estão fora do fecho convexo de acordo com a escala de proporção
        // std::cout << "TESTANO " << current.x << " --- " << current.y << std::endl;
        current.x = static_cast<int>(current.x * 100) / xScale;
        current.y = static_cast<int>(current.y * 100) / yScale;

        // Verifique se as coordenadas estão dentro dos limites e não pertencem ao fecho convexo
        if (current.x <= xMax && current.y <= yMax && !p0.isPointInHull(current, points, n, 0))
        {
            // Desenhe um círculo amarelo representando o ponto com um atraso de 50ms para cada ponto
            fillellipse(current.x, current.y, 3, 3);
            delay(500);
        }
        else
        {
            closegraph();
            // std::cout << current.x << " " << current.y << std::endl;
            throw InvalidCoordinatesException();
        }
    }

    // Comece a desenhar a partir do ponto mais à esquerda
    int currentPoint = leftmost;
    std::cout << "Desenhando as retas..." << std::endl;
    do
    {
        Point current = points[currentPoint];        // O ponto atual no fecho convexo
        Point next = points[(currentPoint + 1) % n]; // O próximo ponto no fecho convexo

        // Redimensione os pontos de acordo com a escala de proporção
        current.x = static_cast<int>((current.x * 100)) / xScale;
        current.y = static_cast<int>((current.y * 100)) / yScale;
        // current.y = static_cast<int>(current.y * yScale);
        next.x = static_cast<int>(next.x * 100) / xScale;
        next.y = static_cast<int>(next.y * 100) / yScale;
        // next.y = static_cast<int>(next.y * yScale);

        // Verifique se as coordenadas estão dentro dos limites
        if (current.x <= xMax && current.y <= yMax && next.x <= xMax && next.y <= yMax)
        {
            // Desenhe a linha entre os pontos com um atraso de 100ms
            line(current.x, current.y, next.x, next.y);
            delay(100);
        }
        else
        {
            closegraph();
            throw InvalidCoordinatesException();
        }

        currentPoint = (currentPoint + 1) % n;
    } while (currentPoint != leftmost);

    std::cout << "Desenhando os pontos dentro do fecho convexo..." << std::endl;
    // Desenhe os pontos do fecho convexo
    for (int i = 0; i < nPoints; i++)
    {
        Point current = hull[i];

        // Redimensione os pontos do fecho convexo de acordo com a escala de proporção
        current.x = static_cast<int>(current.x * 100) / xScale;
        current.y = static_cast<int>(current.y * 100) / yScale;

        // Verifique se as coordenadas estão dentro dos limites
        if (current.x <= xMax && current.y <= yMax)
        {
            // Desenhe um círculo amarelo representando o ponto com um atraso de 20ms
            fillellipse(current.x, current.y, 2, 2);
            delay(20);
        }
        else
        {
            closegraph();
            throw InvalidCoordinatesException();
        }
    }
    delay(800);
    char *msg2 = "UAAAUUU!";
    outtextxy(265, 240, msg2);
    msg2 = "NOTA 10000!";
    delay(1000);
    outtextxy(255, 260, msg2);

    // 3,5 seg de delay
    delay(3500);
    closegraph();
}
