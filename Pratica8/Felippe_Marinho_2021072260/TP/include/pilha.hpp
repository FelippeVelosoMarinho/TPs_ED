//---------------------------------------------------------------------
// Arquivo      : pilha.hpp
// Conteudo     : Classe pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 09/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _PILHA_HPP_
#define _PILHA_HPP_

#include <iostream>
#include "exceptions.hpp"
#include "pilhaPai.hpp"

#define MAXTAM 10000

class Pilha : public PilhaPai
{
public:
    Pilha();
    ~Pilha();

    void Empilha(float item);
    float Desempilha();
    void Limpa();

    // Função que retorna o topo da pilha
    float Topo() { return itens[topo]; };

protected:
    int topo;
    float itens[MAXTAM];
};

#endif