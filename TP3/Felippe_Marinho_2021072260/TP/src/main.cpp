//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Programa de avaliacao do programa de compressao e descompressao de Huffman
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sys/resource.h>
#include "../include/memlog.hpp"
#include "../include/compress.hpp"
#include "../include/decompress.hpp"
#include "../include/tmp.hpp"

/**
 * @brief Função pra descorbrir o tamanho do texto no arquivo
 *
 */
int sizeFile(char *caminho)
{
    FILE *arq;
    int i = 0;

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        throw FileNotFoundException();
        // return NULL;
    }

    while (!feof(arq))
    {
        fgetc(arq);
        i++;
    }

    fclose(arq);

    return i;
}

/**
 * @brief Função pra ler o arquivo
 *
 * @param caminho
 * @return char*
 */
unsigned char *readFile(char *caminho)
{
    FILE *arq;
    unsigned char *texto;
    int i = 0;

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        throw FileNotFoundException();
        return NULL;
    }

    texto = (unsigned char *)malloc(sizeof(char) * sizeFile(caminho));

    while (!feof(arq))
    {
        texto[i] = fgetc(arq);
        i++;
    }

    texto[i] = '\0';

    fclose(arq);

    return texto;
}

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

    if (argc > 1)
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
    }
    Tmp f;
    FrequencyTable *tab = new FrequencyTable();
    List *lista = new List();
    Node *raiz = new Node();
    Tree *tree = new Tree();
    Dictionary *dic = new Dictionary();
    Compress *comp = new Compress();
    Decompress *decomp = new Decompress();
    char *cod, *decod;

    setlocale(LC_ALL, "Portuguese");

    // unsigned char texto[] = "Vamos aprender programação";
    unsigned char *texto = (unsigned char *)readFile(caminho);

    // Chame uma função para gerar os gráficos usando a memlog aqui
    std::cout << "Log gerado em ./tmp/huffmanLog.out" << std::endl;
    char *lognome = "./tmp/huffmanLog.out";
    iniciaMemLog(lognome);
    ativaMemLog();

    // Define a fase 0 do memlog
    defineFaseMemLog(0);
    getrusage(RUSAGE_SELF, &start);

    tab->fillTable(texto);
    // tab->printTable();

    lista->fillList(tab->getTable(), lista);
    // lista->printList();

    raiz = tree->createTree(lista);
    std::cout << "Arvore de Huffman!" << std::endl;
    // tree->printTree(raiz, 0); //

    int columns = tree->treeHeight(raiz) + 1;
    char **dictionary = dic->allocDictionary(columns);

    dic->createDictionary(dictionary, raiz, "", columns);
    // dic->printDictionary(dictionary);

    if (compactar)
    {
        cod = comp->compress(dictionary, texto);
        /*std::cout << "Texto original: " << texto << std::endl;
        std::cout << "Texto codificado: " << cod << std::endl;*/
        comp->compact((unsigned char *)cod);
        std::cout << "Arquivo compactado!" << std::endl;
    }

    if (descompactar)
    {
        decod = decomp->decompress((unsigned char *)cod, raiz);
        // std::cout << "Texto decodificado: " << decod << std::endl;
        decomp->descompact(raiz);
        std::cout << "Arquivo descompactado!" << std::endl;
    }

    delete tab;
    delete lista;
    delete tree;
    delete dic;
    delete comp;
    delete decomp;

    getrusage(RUSAGE_SELF, &end);
    printf("Tempo de usuário: %fs\n", f.diffUserTime(&start, &end));

    return 0; // finalizaMemLog();//
}