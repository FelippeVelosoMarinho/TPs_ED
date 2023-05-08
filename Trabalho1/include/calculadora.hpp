//---------------------------------------------------------------------
// Arquivo      : calculadora.hpp
// Conteudo     : Classe calculadora
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 16/04/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _CALCULADORA_HPP_
#define _CALCULADORA_HPP_

#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include "exceptions.hpp"
#include "pilha.hpp"
#include "pilhaStr.hpp"

using namespace std;

#define MAXTAM 1000

class Calculadora
{
public:
    // Construtor e destrutor
    Calculadora();
    ~Calculadora();

    // Funções para verificar se o caractere é operador ou operando
    bool isOperator(char c);
    bool isOperand(char c);

    // Função para verifica se a expressão é infixa ou posfixa
    int tipoExpressao(const char *filename, char expression[]);

    // Função para ler a expressão do arquivo e retornar a expressão
    char *lerExpressao(const char *filename, char expression[], int expression_type, int exp_conv);

    // Funções para verificar se a expressão é válida
    bool verificaExpressaoInf(char exp[]);
    bool verificaExpressaoPos(char exp[]);

    // Funções para converter a expressão
    char *converteInfToPos(char infixa[], char posfixa[]); // converte infixa para posfixa
    char *convertePostoInf(char posfixa[]);           // converte posfixa para infixa

    // Funções para calcular a expressão
    float calculaPos(char posfixa[]);

    // Função para resolver a expressão utilizando as funções acima
    void resolveExpressao(const char *filename, char expression[], int expression_type, int exp_conv);

private:

    char operacao[MAXTAM];
};

#endif