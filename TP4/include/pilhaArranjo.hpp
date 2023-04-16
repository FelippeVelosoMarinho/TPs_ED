#ifndef _PILHA_ARRANJO_HPP_
#define _PILHA_ARRANJO_HPP_

#include <iostream>
#include <random>

#include "filaArranjo.hpp"

class PilhaArranjo
{
public:
    PilhaArranjo();
    //~PilhaArranjo();

    // A operação criapilha é desnecessária, pois a pilha é criada no construtor
    // void criapilha();

    // A operação destroipilha é desnecessária, pois não há alocação dinâmica de memória no programa
    // void destroipilha();
    void empilha(int n);
    void desempilha();
    void limpapilha();
    int gerarNumeroAleatorio(int minimo, int maximo);
    void operacoes();
    void pilhavazia();

private:
    /*int topo;*/
    static const int MAXTAM = 10;
    FilaArranjo PilhaD;
    FilaArranjo Pilha;

protected:
    int tamanhoPilha;
};

#endif