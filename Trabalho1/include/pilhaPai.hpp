#include <iostream>

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