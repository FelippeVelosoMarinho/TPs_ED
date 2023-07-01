//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao da atividade 6
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 09/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "../include/conversao.hpp"

/**
 * @brief Função principal do programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    Conversao c;
    char infixa[1000] = "( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
    char posfixa[1000];
    c.converteInfToPos(infixa, posfixa);

    return 0;
}