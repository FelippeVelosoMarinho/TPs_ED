#include <iostream>
#include "pilhaPai.hpp"

#define MAXTAM 1000

class Pilha : public PilhaPai
{
public:
    Pilha();
    ~Pilha(){};
 
    void Empilha(float item);
    float Desempilha();
    void Limpa();
    float Topo() { return itens[topo]; };

protected:
    int topo;
    float itens[MAXTAM];
};