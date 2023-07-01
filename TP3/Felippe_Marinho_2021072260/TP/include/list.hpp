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
    unsigned char data;
    unsigned int frequency;
    struct node *esq, *dir, *next;
} Node;

class List
{
private:
    Node *head;
    //Node *tail;
    unsigned int size;

public:
    List();
    ~List();
    void insertNode(unsigned char data, unsigned int frequency);
    void fillList(unsigned int *table);
    void printList();
};

#endif