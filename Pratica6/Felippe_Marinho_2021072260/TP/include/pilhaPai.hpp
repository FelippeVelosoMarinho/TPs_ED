//---------------------------------------------------------------------
// Arquivo      : pilhaPai.hpp
// Conteudo     : Classe pai de pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 09/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _PILHA_PAI_HPP_
#define _PILHA_PAI_HPP_

#include <iostream>

class PilhaPaiStr
{
public:
    PilhaPaiStr() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void EmpilhaStr(char *item) = 0;
    virtual char *DesempilhaStr() = 0;
    virtual void LimpaStr() = 0;

protected:
    int tamanho;
};

class PilhaPai
{
public:
    PilhaPai() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void Empilha(float item) = 0;
    virtual float Desempilha() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

#endif