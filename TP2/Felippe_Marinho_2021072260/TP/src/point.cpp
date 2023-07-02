//---------------------------------------------------------------------
// Arquivo      : point.cpp
// Conteudo     : Classe point
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/point.hpp"

// Inicializando p0 como um objeto estático

Point Point::p0;

/**
 * @brief Construtor da classe Point
 *
 */
Point::Point()
{
    x = 0;
    y = 0;
}

/**
 * @brief Construct a new Point:: Point object
 *
 * @param x
 * @param y
 */
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Destroy the Point:: Point object
 *
 */
Point::~Point()
{
}

/**
 * @brief Função para encontrar o ponto mais à esquerda (menor x)
 *
 * @return int
 */
int Point::getX(int fase)
{
    LEMEMLOG((long int)&(x), sizeof(int), fase);
    return x;
}

/**
 * @brief Função para encontrar o ponto mais à esquerda (menor x)
 *
 * @return int
 */
int Point::getY(int fase)
{
    LEMEMLOG((long int)&(y), sizeof(int), fase);
    return y;
}

/**
 * @brief Função para encontrar o quadrado da distância entre dois pontos
 *
 * @param p1
 * @param p2
 * @return int
 */
// Função para calcular o quadrado da distância entre dois pontos
int Point::distSq(Point p1, Point p2, int fase)
{
    /*ESCREVEMEMLOG((long int)&(p1.x), sizeof(int), fase);
    ESCREVEMEMLOG((long int)&(p2.x), sizeof(int), fase);
    ESCREVEMEMLOG((long int)&(p1.y), sizeof(int), fase);
    ESCREVEMEMLOG((long int)&(p2.y), sizeof(int), fase);*/
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

/**
 * @brief Função para encontrar o quadrado da distância entre dois pontos
 *
 * @param p
 * @return int
 */
int Point::distSquare(Point p, int fase)
{
    int dx = p.x - x;
    int dy = p.y - y;
    /*ESCREVEMEMLOG((long int)&(dx), sizeof(int), fase);
    ESCREVEMEMLOG((long int)&(dy), sizeof(int), fase);*/
    return dx * dx + dy * dy;
}

/**
 * @brief Função para verificar se três pontos são colineares
 *
 * @param p1
 * @param p2
 */
// A utility function to swap two points
void Point::swap(Point &p1, Point &p2, int fase)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
    /*ESCREVEMEMLOG((long int)&(p1.x), sizeof(int), fase);
    ESCREVEMEMLOG((long int)&(p2.x), sizeof(int), fase);*/
}

/**
 * @brief Função para verificar se três pontos são colineares
 *
 * @param p
 * @return double
 */
double Point::computeAngle(Point p, int fase)
{
    double X = p.getX(fase);
    double Y = p.getY(fase);

    double angle = atan2(Y, X);

    return angle;
}

/**
 * @brief Função para verificar se três pontos são colineares
 *
 * @param p
 * @param q
 * @param r
 * @return int
 */
int Point::orientation(Point p, Point q, Point r, int fase)
{
    int val = (q.getY(fase) - p.getY(fase)) * (r.getX(fase) - q.getX(fase)) -
              (q.getX(fase) - p.getX(fase)) * (r.getY(fase) - q.getY(fase));

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

/**
 * @brief Função para verificar se três pontos são colineares
 *
 * @param points
 * @param n
 * @return int
 */
int Point::verifyCollinearPoints(Point *points, int n, int fase)
{
    for (int i = 0; i < n; i++)
        if (points[i].getX(fase) != points[i].getY(fase))
            return 0;
    return 1;
}

/**
 * @brief Função para verificar se três pontos são colineares
 *
 * @param p
 * @param q
 * @param r
 * @return int
 */
int Point::getOrientation(const Point &p, const Point &q, const Point &r, int fase)
{
    /*LEMEMLOG((long int)&(p.x), sizeof(int), fase);
    LEMEMLOG((long int)&(q.x), sizeof(int), fase);
    LEMEMLOG((long int)&(r.x), sizeof(int), fase);
    LEMEMLOG((long int)&(p.y), sizeof(int), fase);
    LEMEMLOG((long int)&(q.y), sizeof(int), fase);
    LEMEMLOG((long int)&(r.y), sizeof(int), fase);*/
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // Pontos são colineares

    return (val > 0) ? 1 : -1; // 1 para orientação horária, -1 para anti-horária
}

/**
 * @brief Função para verificar se três pontos são colineares
 *
 * @param point  Pontos do fecho convexo
 * @param hull   Array com todos os pontos
 * @param n
 * @return true
 * @return false
 */
bool Point::isPointInHull(const Point &point, Point hull[], int n, int fase)
{
    // Verifique se o ponto está à esquerda ou à direita de todas as arestas do fecho convexo
    for (int i = 0; i < n; i++)
    {
        Point current = hull[i];
        Point next = hull[(i + 1) % n];

        // Calcule a orientação do ponto em relação à aresta do fecho convexo
        int orientation = getOrientation(current, next, point, fase);

        // Se o ponto estiver à direita de qualquer aresta, não pertence ao fecho convexo
        if (orientation == -1)
            return false;
    }

    // O ponto está à esquerda de todas as arestas, pertence ao fecho convexo
    return true;
}