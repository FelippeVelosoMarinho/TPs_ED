// Arquivo      : decompress.hpp
// Conteudo     : Classes da descompressão
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#ifndef _DECOMPRESS_HPP_
#define _DECOMPRESS_HPP_

#include <stdio.h>
#include <fstream>
#include <cstring>
#include "dictionary.hpp"

class Decompress
{
public:
    Decompress();
    ~Decompress();
    char* decompress(unsigned char *texto, Node *root); // Função para descodificar o texto
    unsigned int isBitOne(unsigned char byte, int pos);
    unsigned char* descompactar(char *caminho);
};

#endif