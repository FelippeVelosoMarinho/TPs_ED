// Arquivo      : frequencyTable.hpp
// Conteudo     : Classes da tabela de frequência
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//-----

#ifndef _FREQUENCY_TABLE_HPP_
#define _FREQUENCY_TABLE_HPP_
#define MAX_SIZE 256

#include <iostream>
#include <locale.h>

#include "memlog.hpp"
#include "exceptions.hpp"

using namespace std;

class FrequencyTable
{
private:
    unsigned int *table;
    unsigned int size;

public:
    FrequencyTable();
    ~FrequencyTable();
    unsigned int *getTable() { return this->table; }
    void setTable(unsigned int *table);
    void setTableWithZero(unsigned int *table);
    void fillTable(unsigned char *text);
    void printTable();
};

#endif