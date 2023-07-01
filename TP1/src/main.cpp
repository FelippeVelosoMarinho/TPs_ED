//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao da calculadora
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 16/04/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>

#include "calculadora.hpp"

/**
 * @brief Função principal do programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    Calculadora calc;
    // char caminho[MAXTAM] = "./enters/entdouble.s2.n5.p.in";
    char *caminho;
    if (argc > 1)
    {
        caminho = argv[1];
    }
    else
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo>" << std::endl;
        return 1;
    }

    char expr[MAXTAM];

    calc.resolveExpressao(caminho, expr, 0, 0);

    return 0;
}