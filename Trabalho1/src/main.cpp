#include <iostream>

#include "calculadora.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Calculadora calc;

    char expr[MAXTAM];
    //char infixa[MAXTAM] = "( 2.000000 + 3.400000 * 4.000000)";
    //char infixa2[MAXTAM] = "( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
    //char posfixa[MAXTAM] = "2 3.4 4 * +"; //5 3 2 x +   
    //calc.convertePos(posfixa, expr);
    //calc.calculaInf(infixa);
    //cout << "calculo? "<< calc.calculaPos(posfixa) << endl;
    
    //calc.converteInf(infixa2, expr);
    //calc.lerExpressao("./enters/entdouble.s1.n5.i.in", expr, 0, 0);
    calc.resolveExpressao("./enters/entdouble.s2.n5.p.in", expr, 0, 0);
    //calc.convertePos(posfixa);
    //printf("Resultado: %s", resultado);

    return 0;
}