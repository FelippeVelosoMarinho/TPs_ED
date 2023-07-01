#include "../include/filaArranjo.hpp"

FilaArranjo::FilaArranjo()
{
    frente = 0;
    tras = 0;
}

int FilaArranjo::GetTamanho() { return tamanho; };

bool FilaArranjo::Vazia()
{
    if (tamanho == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void FilaArranjo::Enfileira(int item)
{
    if (tamanho == MAXTAM)
        throw "Fila Cheia!";

    itensF[tras] = item;
    // fila circular
    tras = (tras + 1) % MAXTAM;
    tamanho++;
}

int FilaArranjo::Desenfileira()
{
    if (tamanho == 0)
        throw "Fila Vazia!";

    int item = itensF[frente];
    // fila circular
    frente = (frente + 1) % MAXTAM;
    tamanho--;
    return item;
}

void FilaArranjo::Limpa()
{
    frente = 0;
    tras = 0;
    tamanho = 0;
}

void FilaArranjo::imprime()
{
    int i = frente;
    while (i != tras)
    {
        std::cout << itensF[i] << " ";
        i = (i + 1) % MAXTAM;
    }
    std::cout << std::endl;
}