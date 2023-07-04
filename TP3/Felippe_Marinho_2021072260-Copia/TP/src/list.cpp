//---------------------------------------------------------------------
// Arquivo      : list.cpp
// Conteudo     : Implementacao da classe lista encadeada
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/list.hpp"

/**
 * @brief Construtor da classe List
 *
 */
List::List()
{
    this->inicio = NULL;
    this->size = 0;
}

/**
 * @brief Destrutor da classe List
 *
 */
List::~List()
{
    Node *aux = this->inicio;
    while (aux != NULL)
    {
        Node *temp = aux->next;
        delete aux;
        aux = temp;
    }
}

/**
 * @brief Função para retornar o tamanho da lista
 *
 * @return unsigned int
 */
unsigned int List::getSize()
{
    LEMEMLOG(this->size, sizeof(unsigned int), 1);
    return this->size;
}

/**
 * @brief Função para retornar o inicio da lista
 *
 * @return Node*
 */
Node *List::getInicio()
{
    return this->inicio;
}

/**
 * @brief Função para inserir um nó na lista
 *
 * @param void
 */
void List::insertNode(List *list, Node *novo)
{
    // a lista esta vazia?
    if (list->inicio == NULL)
    {
        list->inicio = novo;
    }
    // tem a frequencia menor que o inicio da lista
    else if (list->inicio->frequency > novo->frequency)
    {
        novo->next = list->inicio;
        list->inicio = novo;
    }
    else
    {
        Node *aux = list->inicio;

        while (aux->next != NULL && aux->next->frequency < novo->frequency)
        {
            aux = aux->next;
        }
        novo->next = aux->next;
        aux->next = novo;
    }
    list->size++;
}

/**
 * @brief Função para preencher a lista encadeada
 *
 * @param table
 */
void List::fillList(unsigned int *table, List *list)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (table[i] > 0)
        {
            Node *novo = new Node;
            novo->caracter = i;
            novo->frequency = table[i];
            novo->esq = NULL;
            novo->dir = NULL;
            novo->next = NULL;
            this->insertNode(list, novo);
        }
    }
}

/**
 * @brief Função para remover o primeiro nó da lista
 *
 * @param list
 * @return Node*
 */
Node *List::removeInBegin(List *list)
{
    if (list->inicio == NULL)
    {
        throw EmptyListException();
    }
    else
    {
        Node *aux = list->inicio;
        list->inicio = list->inicio->next;
        list->size--;
        return aux;
    }
}

/**
 * @brief Função para imprimir a lista encadeada
 *
 */
void List::printList()
{
    Node *aux = this->inicio;
    std::cout << "Lista encadeada:" << std::endl;
    while (aux != NULL)
    {
        std::cout << aux->caracter << " " << aux->frequency << std::endl;
        aux = aux->next;
    }
}