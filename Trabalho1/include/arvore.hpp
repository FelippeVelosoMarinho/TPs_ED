//---------------------------------------------------------------------
// Arquivo      : arvore.hpp
// Conteudo     : Classe arvore
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 07/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _ARVORE_HPP_
#define _ARVORE_HPP_

#include <iostream>
#include "pilha.hpp"
#include "exceptions.hpp"

class No
{
public:
    No();
    ~No();

private:
    char item;
    No *esq;
    No *dir;

    friend class Arvore;
};

class Arvore
{
public:
    Arvore();
    ~Arvore();

    void Insere(char item);
    void Caminha(int tipo);
    void Limpa();

private:
    void InsereRecursivo(No *&p, char item);
    void ApagaRecursivo(No *p);
    void PorNivel();
    void PreOrdem(No *p);
    void InOrdem(No *p);
    void PosOrdem(No *p);

    No *raiz;
};

#endif