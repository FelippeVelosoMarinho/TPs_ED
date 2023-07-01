#ifndef _FILA_ARRANJO_HPP_
#define _FILA_ARRANJO_HPP_

#include <iostream>

class FilaArranjo
{
public:
    FilaArranjo();

    int GetTamanho();
    void Enfileira(int item);
    int Desenfileira();
    bool Vazia();
    void Limpa();
    void imprime();

private:
    int frente;
    int tras;
    static const int MAXTAM = 10;
    int itensF[MAXTAM];

protected:
    int tamanho;
};

#endif