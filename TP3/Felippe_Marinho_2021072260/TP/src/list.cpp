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
    this->head = new Node; // Aloca um novo nó para a cabeça da lista
    this->head->next = NULL;
    this->size = 0;
    // this->head = NULL;
    // this->tail = NULL;
    this->size = 0;
}

/**
 * @brief Destrutor da classe List
 *
 */
List::~List()
{
    Node *aux = this->head;
    Node *aux2 = NULL;

    while (aux != NULL)
    {
        aux2 = aux->next;
        delete aux;
        aux = aux2;
    }
}

/**
 * @brief Função para inserir um nó na lista
 *
 * @param data
 * @param frequency
 */
void List::insertNode(unsigned char data, unsigned int frequency)
{
    // a lista esta vazia
    if (this->head == NULL)
    {
        this->head = new Node;
        // this->size++;
    }
    // tem frequencia menor q o inicio da lista
    else if (this->head->frequency < frequency)
    {
        Node *aux = new Node;
        aux->data = data;
        aux->frequency = frequency;
        aux->next = this->head;
        this->head = aux;
        // this->size++;
    }
    // a lista tem um elemento
    else if (this->head->next == NULL)
    {
        Node *aux = new Node;
        aux->data = data;
        aux->frequency = frequency;
        aux->next = NULL;
        this->head->next = aux;
        // this->size++;
    }
    // a lista tem mais de um elemento
    else
    {
        Node *aux = this->head;
        Node *aux2 = this->head->next;

        while (aux2 != NULL && aux2->frequency < frequency)
        {
            aux = aux->next;
            aux2 = aux2->next;
        }

        Node *aux3 = new Node;
        aux3->data = data;
        aux3->frequency = frequency;
        aux3->next = aux2;
        aux->next = aux3;
        // this->size++;
    }
    this->size++;
    // this->tail = aux;
}

/**
 * @brief Função para preencher a lista
 *
 * @param table
 */
void List::fillList(unsigned int *table)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        this->insertNode(i, table[i]);
        /*if (table[i] != 0)
        {
            this->insertNode(i, table[i]);
        }
        else
        {
            throw FillListErrorException();
        }*/
    }
}

/**
 * @brief Função para imprimir a lista
 *
 */
void List::printList()
{
    Node *aux = this->head;
    std::cout << "Lista ordenada: " << std::endl;

    while (aux != NULL)
    {
        /*std::cout << aux->data << " " << aux->frequency << std::endl;
        aux = aux->next;*/
        if (aux->frequency > 0)
        {
            std::cout << aux->data << " " << aux->frequency << std::endl;
        }
        aux = aux->next;
    }
}