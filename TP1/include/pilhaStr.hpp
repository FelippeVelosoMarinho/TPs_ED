//---------------------------------------------------------------------
// Arquivo      : pilhaStr.hpp
// Conteudo     : Classe pilhaStr
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 08/05/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef _PILHA_STR_HPP_
#define _PILHA_STR_HPP_

#include <iostream>
#include "exceptions.hpp"
#include "pilhaPai.hpp"

#define MAXTAM 1000

class PilhaStr : public PilhaPaiStr
{
public:
    PilhaStr();
    ~PilhaStr();
 
    void EmpilhaStr(char *item);
    char *DesempilhaStr();
    void LimpaStr();   

    // Função que retorna o topo da pilha
    char *TopoStr() { return itens[topo]; };

protected:
    int topo;
    char *itens[MAXTAM];
};

#endif