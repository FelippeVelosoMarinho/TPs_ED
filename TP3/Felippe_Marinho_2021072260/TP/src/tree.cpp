//---------------------------------------------------------------------
// Arquivo      : tree.cpp
// Conteudo     : Implementacao da classe de arvore
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/tree.hpp"

/**
 * @brief Construtor da classe Tree
 *
 */
Tree::Tree()
{
    this->raiz = NULL;
}

/**
 * @brief Destrutor da classe Tree
 *
 */
Tree::~Tree()
{
    if (this->raiz != NULL)
    {
        delete this->raiz;
    }
}

/**
 * @brief Função para criar a arvore
 *
 * @param list
 * @return Node*
 */
Node *Tree::createTree(List *list)
{
    Node *first, *second;
    List *aux;
    while (list->getSize() > 1)
    {
        first = aux->removeInBegin(list);
        second = aux->removeInBegin(list);

        Node *novo = new Node;
        if (novo)
        {
            novo->caracter = '*'; // caracter intermediario para indicar que é um nó, indiferente o valor
            novo->frequency = first->frequency + second->frequency;
            novo->esq = first;
            novo->dir = second;
            novo->next = NULL;

            aux->insertNode(list, novo);
        }
        else
        {
            throw AllocationErrorException();
        }
    }
    return list->getInicio();
}

/**
 * @brief Função para imprimir a arvore
 *
 * @param raiz
 * @param size
 */
void Tree::printTree(Node *raiz, int size)
{
    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        std::cout << "Folha: " << raiz->caracter << " Altura: " << size << std::endl;
    }
    else
    {
        this->printTree(raiz->esq, size + 1);
        this->printTree(raiz->dir, size + 1);
    }
}

/**
 * @brief Função para retornar a altura da arvore
 *
 * @param raiz
 * @return int
 */
int Tree::treeHeight(Node *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int he = this->treeHeight(raiz->esq);
        int hd = this->treeHeight(raiz->dir);
        if (he < hd)
        {
            return hd + 1;
        }
        else
        {
            return he + 1;
        }
    }
}
