// Arquivo      : list.hpp
// Conteudo     : Classes da lista encadeada
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//-----

#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <iostream>
#include <cstddef>

#include "exceptions.hpp"
#include "frequencyTable.hpp"

typedef struct node
{
    unsigned char caracter;
    unsigned int frequency;
    struct node *esq, *dir, *next;
} Node;

class List
{
private:
    Node *inicio;
    unsigned int size;

public:
    List();
    ~List();
    unsigned int getSize();
    Node *getInicio();
    void insertNode(List *list, Node *novo);
    void fillList(unsigned int *table, List *list);
    Node *removeInBegin(List *list);
    void printList();
};

#endif