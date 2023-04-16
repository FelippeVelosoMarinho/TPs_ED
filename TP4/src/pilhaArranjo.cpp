#include "../include/pilhaArranjo.hpp"

PilhaArranjo::PilhaArranjo()
{
    tamanhoPilha = 0;
};

int PilhaArranjo::gerarNumeroAleatorio(int minimo, int maximo)
{
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<int> distribuicao(minimo, maximo);
    return distribuicao(gerador);
}

void PilhaArranjo::empilha(int num)
{
    if (Pilha.GetTamanho() == MAXTAM)
    {
        std::cout << "Pilha vazia!" << std::endl;
        return;
    }
    // Pego uma fila auxiliar e desenfileiro os itens
    FilaArranjo fila;
    fila.Enfileira(num);

    int tamanho = fila.GetTamanho();
    std::cout << "Numero a ser empilhado: " << num << std::endl;
    for (int i = 0; i < tamanho - 1; i++)
    {
        tamanhoPilha++;
    }
    Pilha.Enfileira(fila.Desenfileira());
    // Imprime Fila após deixar somente o último item ou o ultimo item da Pilha
    Pilha.imprime();
}

void PilhaArranjo::desempilha()
{
    if (Pilha.GetTamanho() == 0)
    {
        std::cout << "Pilha vazia!" << std::endl;
        return;
    }
    // Utilizo o atributo PilhaD como uma pilha auxiliar que ficará os itens da pulha desempilhada
    FilaArranjo PilhaD;
    int tamanho = Pilha.GetTamanho();
    for (int i = 0; i < tamanho - 1; i++)
    {
        PilhaD.Enfileira(Pilha.Desenfileira());
    }
    int elementoDesempilhado = Pilha.Desenfileira();
    tamanhoPilha = tamanho - 1;
    std::cout << "Numero desempilhado: " << elementoDesempilhado << std::endl;
    // Inverte a ordem dos elementos da pilha auxiliar e adiciona-os novamente na pilha original
    for (int i = 0; i < tamanho - 1; i++)
    {
        Pilha.Enfileira(PilhaD.Desenfileira());
    }
    Pilha.imprime();
}

void PilhaArranjo::limpapilha()
{
    Pilha.Limpa();
    PilhaD.Limpa();
    std::cout << "\nPilha limpa!\n"
              << std::endl;
}

void PilhaArranjo::pilhavazia()
{
    if (Pilha.GetTamanho() == 0)
    {
        std::cout << "A pilha esta vazia!" << std::endl;
        return;
    }
    std::cout << "A pilha nao esta vazia!" << std::endl;
}

void PilhaArranjo::operacoes()
{
    int num = 0;
    int contador = 0;
    // Empilhando alguns elementos somente para nao ficar sem graca
    empilha(gerarNumeroAleatorio(0, 9));
    empilha(gerarNumeroAleatorio(0, 9));
    empilha(gerarNumeroAleatorio(0, 9));
    while (contador < 30)
    {
        std::cout << "----- Operacao " << contador + 1 << " -----" << std::endl;
        switch (gerarNumeroAleatorio(1, 3))
        {
        case 1:
            num = gerarNumeroAleatorio(0, 9);
            empilha(num);
            break;
        case 2:
            desempilha();
            break;
        case 3:
            pilhavazia();
            break;
        }
        contador++;
    }
    // limpa a pilha para nao ficar poluindo a memoria e testar a funcao
    limpapilha();
}