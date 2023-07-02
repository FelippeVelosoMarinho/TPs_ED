// Arquivo      : compress.hpp
// Conteudo     : Classes da compressão
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#ifndef _COMPRESS_HPP_
#define _COMPRESS_HPP_

#include <stdio.h>
#include "dictionary.hpp"

class Compress
{
private:
    char *fileInput;
    char *fileOutput;
    char **dictionary;
    int sizeDictionary;
public:
    Compress();
    ~Compress();
    int stringSize(char **dictionary, unsigned char *string);
    char* compress(char **dictionary, unsigned char *string); 
    void compact(unsigned char *caminho);
};

#endif