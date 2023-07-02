// Arquivo      : dictionary.cpp
// Conteudo     : Implementação da classe dicionário
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#include "../include/dictionary.hpp"

/**
 * @brief Construtor da classe Dictionary
 *
 */
Dictionary::Dictionary()
{
    /*this->dictionary = new char *[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        this->dictionary[i] = NULL;
    }*/
}

/**
 * @brief Destrutor da classe Dictionary
 *
 */
Dictionary::~Dictionary()
{
    if (this->dictionary != NULL)
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (this->dictionary[i] != NULL)
            {
                delete[] this->dictionary[i];
            }
        }
        delete[] this->dictionary;
    }
}

/**
 * @brief Função para alocar o dicionário
 *
 * @param columns
 * @return char**
 */
char **Dictionary::allocDictionary(int columns)
{
    char **dictionary = (char **)malloc(sizeof(char *) * MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        dictionary[i] = (char *)calloc(columns, sizeof(char));
    }

    return dictionary;
}

/**
 * @brief Função para criar o dicionário
 *
 * @param raiz
 * @param code
 * @param size
 */
void Dictionary::createDictionary(char **dictionary, Node *raiz, char *code, int size)
{
    if (raiz == nullptr)
    {
        return;
    }
    char esquerda[size], direita[size];

    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        strcpy(dictionary[(int)raiz->caracter], code);
    }
    else if (raiz->dir != NULL)
    {
        strcpy(esquerda, code);
        strcpy(direita, code);

        strcat(esquerda, "0");
        strcat(direita, "1");

        this->createDictionary(dictionary, raiz->esq, esquerda, size);
        this->createDictionary(dictionary, raiz->dir, direita, size);
    }
}

/**
 * @brief Função para imprimir o dicionário
 *
 */
void Dictionary::printDictionary(char **dictionary)
{
    int i;
    std::cout << "Dicionario:" << std::endl;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (strlen(dictionary[i]) > 0)
        {
            std::cout << i << " - " << dictionary[i] << std::endl;
        }
    }
}
