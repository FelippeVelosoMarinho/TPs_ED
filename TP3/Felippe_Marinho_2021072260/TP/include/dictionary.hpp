// Arquivo      : dictionary.hpp
// Conteudo     : Classes da dicionário
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#ifndef _DICTIONARY_HPP_
#define _DICTIONARY_HPP_

#include <stdio.h>
#include "tree.hpp"

class Dictionary
{
private:
    char **dictionary;
public:
    Dictionary();
    ~Dictionary();
    char **allocDictionary(int columns);
    void freeDictionary(char **dictionary, int columns);
    void createDictionary(char**dictionary, Node *raiz, char *code, int size);
    void printDictionary(char **dictionary);
};

#endif