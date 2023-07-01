// Arquivo      : tree.hpp
// Conteudo     : Classes da arvore
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <string.h>
#include "list.hpp"

class Tree
{
private:
    Node *raiz;

public:
    Tree();
    ~Tree();
    Node* createTree(List *list);
    void printTree(Node *raiz, int size);
    int treeHeight(Node *raiz);
    char **allocDictionary(int columns);
    void createDictionary(Node *raiz, char **dictionary, char *code, int size);
    void printDictionary(char **dictionary, int columns);
};

#endif