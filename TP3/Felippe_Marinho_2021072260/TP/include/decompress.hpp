// Arquivo      : decompress.hpp
// Conteudo     : Classes da descompressão
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#ifndef _DECOMPRESS_HPP_
#define _DECOMPRESS_HPP_

#include <stdio.h>
#include "dictionary.hpp"

class Decompress
{
private:
    char *fileInput;
    char *fileOutput;
    char **dictionary;
    int sizeDictionary;
public:
    Decompress();
    ~Decompress();
    char* decompress(unsigned char *texto, Node *root);
    unsigned int isBitOne(unsigned char byte, int pos);
    void descompact(Node *root);
};

#endif