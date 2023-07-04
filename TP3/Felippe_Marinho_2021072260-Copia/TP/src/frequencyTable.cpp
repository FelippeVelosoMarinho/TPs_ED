//---------------------------------------------------------------------
// Arquivo      : frequencyTable.cpp
// Conteudo     : Implementacao da classe de tabela de frequência
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/frequencyTable.hpp"

/**
 * @brief Construtor da classe FrequencyTable
 *
 */
FrequencyTable::FrequencyTable()
{
    this->table = new unsigned int[MAX_SIZE];
    this->size = 0;
}

/**
 * @brief Destrutor da classe FrequencyTable
 *
 */
FrequencyTable::~FrequencyTable()
{
    delete[] this->table;
}

/**
 * @brief Função para setar a tabela de frequência
 *
 * @param table
 */
void FrequencyTable::setTable(unsigned int *table)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        ESCREVEMEMLOG(i, sizeof(unsigned int), 0);
        this->table[i] = table[i];
    }
}

/**
 * @brief Função para setar a tabela de frequência com 0
 *
 * @param table
 */
void FrequencyTable::setTableWithZero(unsigned int *table)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        ESCREVEMEMLOG(i, sizeof(unsigned int), 0);
        this->table[i] = 0;
    }
}

/**
 * @brief Função para preencher a tabela de frequência
 *
 * @param text
 * @param tab
 */
void FrequencyTable::fillTable(unsigned char *text)
{
    int i = 0;

    while (text[i] != '\0')
    {
        ESCREVEMEMLOG(text[i], sizeof(unsigned int), 0);
        this->table[text[i]]++;
        i++;
    }
}

/**
 * @brief Função para imprimir a tabela de frequência
 *
 */
void FrequencyTable::printTable()
{
    std::cout << "Tabela de frequência:" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (this->table[i] != 0)
        {
            //std::cout << i << " - " << (char)i << " - " << this->table[i] << std::endl;
            LEMEMLOG(i, sizeof(unsigned int), 0);
            printf("%d - %u - %d\n", i, (char)i, this->table[i]);
        }
    }
}
