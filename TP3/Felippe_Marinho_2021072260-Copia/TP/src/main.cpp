//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao do programa de compressao e descompressao de Huffman
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/program.hpp"

/**
 * @brief Função principal do programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    Program p;
    p.printMenu(argc, argv);

    return 0;
}