//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao do fecho complexo
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sys/resource.h>
#include "../include/memlog.hpp"
#include "../include/tree.hpp"

/**
 * @brief Função principal do programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{

    struct rusage start, end; // Structs para medir o tempo de execução

    srand(time(NULL));

    int numPoints = 0;
    char *caminho;
    bool descompactar = false;
    bool compactar = false;

    /*if (argc > 1)
    {
        caminho = argv[1];

        for (int i = 2; i < argc; i++)
        {
            if (strcmp(argv[i], "-d") == 0)
            {
                descompactar = true;
            }
            else if (strcmp(argv[i], "-c") == 0)
            {
                compactar = true;
            }
        }
    }
    else
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo> [-d] [-c]" << std::endl;
        return 1;
    }*/
    if (compactar || descompactar)
    {
        // Chame uma função para gerar os gráficos usando a memlog aqui
        std::cout << "Log gerado em ./tmp/huffmanLog.out" << std::endl;
        char *lognome = "./tmp/huffmanLog.out";
        iniciaMemLog(lognome);
        ativaMemLog();
    }
    FrequencyTable *tab = new FrequencyTable();
    List *lista = new List();
    Node *raiz = new Node();
    Tree *tree = new Tree();

    setlocale(LC_ALL, "Portuguese");

    unsigned char texto[] = "Vamos aprender programação";

    tab->fillTable(texto);
    tab->printTable();

    lista->fillList(tab->getTable(), lista);
    lista->printList();

    raiz = tree->createTree(lista); //&lista
    std::cout << "Arvore de Huffman!" << std::endl;
    tree->printTree(raiz, 0); // lista->getSize()

    int columns = tree->treeHeight(raiz) + 1;
    char **dictionary = tree->allocDictionary(columns);
    tree->createDictionary(raiz, dictionary, new char[columns], columns); //new char[columns]
    tree->printDictionary(dictionary, columns);

    // Define a fase 0 do memlog
    /*defineFaseMemLog(0); 
    getrusage(RUSAGE_SELF, &start);

    getrusage(RUSAGE_SELF, &end);*/

    if (compactar || descompactar)
    {
        // Chame uma função para gerar os gráficos usando a memlog aqui
        std::cout << "Geração de log finalizada!" << std::endl;
        return finalizaMemLog();
    }

    return 0;
}