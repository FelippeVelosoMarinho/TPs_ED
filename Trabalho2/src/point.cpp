#include "../include/point.hpp"

// Inicializando p0 como um objeto estático
Point Point::p0;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

// Função para calcular o quadrado da distância entre dois pontos
int Point::distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// A utility function to swap two points
void Point::swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

double Point::computeAngle(Point p)
{
    double X = p.getX();
    double Y = p.getY();

    double angle = atan2(Y, X);

    return angle;
}

int Point::orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

int Point::distSquare(Point p)
{
    int dx = p.x - x;
    int dy = p.y - y;
    return dx * dx + dy * dy;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

int Point::compare(const void *vp1, const void *vp2)
{

    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}