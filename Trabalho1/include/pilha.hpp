//---------------------------------------------------------------------
// Arquivo      : pilha.hpp
// Conteudo     : Classe pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 16/04/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _PILHA_HPP_
#define _PILHA_HPP_

#include <iostream>
#include "pilhaPai.hpp"

#define MAXTAM 1000

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