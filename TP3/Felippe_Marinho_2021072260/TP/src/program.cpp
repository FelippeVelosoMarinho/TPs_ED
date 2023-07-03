// Arquivo      : program.cpp
// Conteudo     : Classes de implementação das funções principais do programa
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 02/07/2023 - arquivo criado
//-----

#include "../include/program.hpp"

/**
 * @brief Função para calcular quantos caracteres tem o arquivo
 *
 * @param caminho
 * @return int
 */
int Program::sizeFile(char *caminho)
{
    FILE *arq;
    int i = 0;

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        throw FileNotFoundException();
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
 * @brief Função para ler o arquivo
 *
 * @param caminho
 * @return unsigned char*
 */
unsigned char *Program::readFile(char *caminho)
{
    FILE *arq;
    unsigned char *texto;
    int i = 0;

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        throw FileNotFoundException();
    }

    texto = (unsigned char *)malloc(sizeof(char) * this->sizeFile(caminho));

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
 * @brief Função para processar os argumentos de linha de comando
 *
 * @param argc
 * @param argv
 * @param caminho
 * @param descompactar
 * @param compactar
 * @return bool
 */
bool Program::processArguments(int argc, char *argv[], char *&caminho, bool &descompactar, bool &compactar)
{
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
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Função para calcular o tamanho do arquivo em bytes
 *
 * @param caminho
 * @return int
 */
int Program::sizeFileBytes(char *caminho)
{
    std::ifstream arquivo(caminho, std::ios::binary);
    if (!arquivo)
    {
        throw FileNotFoundException();
    }

    arquivo.seekg(0, std::ios::end);          // Move o ponteiro para o final do arquivo
    std::streampos tamanho = arquivo.tellg(); // Obtém a posição atual do ponteiro (que é o tamanho do arquivo)
    arquivo.close();

    return static_cast<int>(tamanho);
}

/**
 * @brief Função auxiliar que salva um arquivo contendo o texto original em um arquivo txt
 *
 * @param caminho
 * @param texto
 */
void Program::salvarArquivo(unsigned char *texto)
{
    FILE *arq = fopen("./tmp/aux.txt", "w"); // Arquivo txt
    int i = 0;

    while (texto[i] != '\0')
    {
        fputc(texto[i], arq);
        i++;
    }

    std::cout << GREEN << "√ Arquivo auxiliar criado em './tmp/aux.txt'" << RESET << std::endl;
    fclose(arq);
}

/**
 * @brief Função auxiliar que salva um arquivo contendo o texto descompactado em um arquivo txt
 *
 * @param caminho
 * @param texto
 */
void Program::salvarArquivoDescompactado(unsigned char *texto)
{
    FILE *arq = fopen("descompactado.txt", "w"); // Arquivo txt
    int i = 0;

    while (texto[i] != '\0')
    {
        fputc(texto[i], arq);
        i++;
    }

    std::cout << GREEN << "√ Arquivo descompactado criado 'descompactado.txt'" << RESET << std::endl;
    fclose(arq);
}

/**
 * @brief Função auxiliar que salva a tabela de frequência em um arquivo binário
 *
 * @param tabela
 */
void Program::salvarTabelaFrequencia(const int *tabela)
{
    FILE *arq = fopen("./tmp/tabela.bin", "wb"); // Arquivo binário

    if (arq)
    {
        fwrite(tabela, sizeof(int), 256, arq); // Escreve a tabela de frequência no arquivo
        fclose(arq);
        std::cout << GREEN << "√ Tabela de frequência salva em './tmp/tabela.bin'" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "X Erro ao salvar a tabela de frequência" << RESET << std::endl;
        throw FileErrorException();
    }
}

/**
 * @brief Função auxiliar para carregar a tabela de frequência de um arquivo binário
 *
 * @return int* - Ponteiro para a tabela de frequência
 */
int *Program::carregarTabelaFrequencia()
{
    FILE *arq = fopen("./tmp/tabela.bin", "rb"); // Arquivo binário
    int *tabela = new int[256];

    if (arq)
    {
        fread(tabela, sizeof(int), 256, arq); // Lê a tabela de frequência do arquivo
        fclose(arq);
        std::cout << GREEN << "√ Tabela de frequência carregada" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "X Erro ao carregar a tabela de frequência" << RESET << std::endl;
        throw FileErrorException();
    }

    return tabela;
}

/**
 * @brief Função para imprimir o menu
 *
 */
int Program::printMenu(int argc, char *argv[])
{
    char *caminho;
    bool descompactar = false;
    bool compactar = false;

    struct rusage start, end; // Structs para medir o tempo de execução

    if (!this->processArguments(argc, argv, caminho, descompactar, compactar))
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo> [-d] [-c]" << std::endl;
        return 1;
    }

    Tmp t;
    FrequencyTable *tab = new FrequencyTable();
    List *lista = new List();
    Node *raiz;
    Tree *tree = new Tree();
    Dictionary *dic = new Dictionary();
    Compress *comp = new Compress();
    Decompress *decomp = new Decompress();
    char *cod, *decod;
    int beforeSize, afterSize;

    setlocale(LC_ALL, "Portuguese"); // Define a localidade para o português

    std::cout << YELLOW << "Carregando arquivo..." << RESET << std::endl;
    unsigned char *texto = (unsigned char *)this->readFile(caminho); // Lê o arquivo

    // Chame uma função para gerar os gráficos usando a memlog aqui
    std::cout << GREEN << "√ Log gerado em './tmp/huffmanLog.out'" << RESET << std::endl;
    char *lognome = "./tmp/huffmanLog.out";
    iniciaMemLog(lognome);
    ativaMemLog();

    // Define a fase 0 do memlog
    defineFaseMemLog(0);
    // Inicializa o contador de pontos
    getrusage(RUSAGE_SELF, &start);

    // Compactar o texto
    if (compactar)
    {
        tab->fillTable(texto); // Cria a tabela de frequência
        // tab->printTable();

        this->salvarTabelaFrequencia((const int *)tab->getTable()); // Salva a tabela de frequência em um arquivo binário auxiliar

        // Criar a lista de nós
        lista->fillList(tab->getTable(), lista);
        // lista->printList();

        // Criar a árvore de Huffman
        raiz = tree->createTree(lista);
        // std::cout << "Arvore de Huffman!" << std::endl;
        // tree->printTree(raiz, 0); //

        // Criar o dicionário
        int columns = tree->treeHeight(raiz) + 1;
        char **dictionary = dic->allocDictionary(columns);

        dic->createDictionary(dictionary, raiz, "", columns);
        // dic->printDictionary(dictionary);
        cod = comp->compress(dictionary, texto);
        /*std::cout << "Texto original: " << texto << std::endl;
        std::cout << "Texto codificado: " << cod << std::endl;*/
        comp->compact((unsigned char *)cod);
        std::cout << GREEN << "√ Arquivo compactado!" << RESET << std::endl;

        beforeSize = this->sizeFileBytes(caminho);          // Tamanho do arquivo original
        afterSize = this->sizeFileBytes("./compactado.wg"); // Tamanho do arquivo compactado
        std::cout << MAGENTA << "\nDe " << beforeSize << " bytes para " << afterSize << " bytes..." << RESET << std::endl;
        std::cout << CYAN << " --- Fator de compressão: " << (float)beforeSize / afterSize << " ---" << RESET << std::endl;
        std::cout << CYAN << " --- Taxa de compressão: " << (float)afterSize / beforeSize * 100 << "% ---" << RESET << std::endl;
    }

    // Descompactar o texto
    if (descompactar)
    {
        unsigned char *textoDescompactado = decomp->descompactar();

        int *tabela = carregarTabelaFrequencia(); // Carrega a tabela de frequência do arquivo auxiliar

        std::cout << YELLOW << "CARREGANDO..." << RESET << std::endl;
        // lista->fillList(tab->getTable(), lista);
        lista->fillList((unsigned int *)tabela, lista); // Cria a lista de nós

        raiz = tree->createTree(lista);

        // Criar o dicionário
        int columns = tree->treeHeight(raiz) + 1;
        char **dictionary = dic->allocDictionary(columns);

        dic->createDictionary(dictionary, raiz, "", columns);

        decod = decomp->decompress(textoDescompactado, raiz);
        // std::cout << "Texto decodificado: " << decod << std::endl;

        this->salvarArquivoDescompactado((unsigned char *)decod); // Salva o arquivo descompactado em um txt
    }

    // Libera a memória alocada
    delete tab;
    delete lista;
    delete tree;
    delete dic;
    delete comp;
    delete decomp;

    getrusage(RUSAGE_SELF, &end);
    std::cout << YELLOW << "\nTempo de usuário: " << t.diffUserTime(&start, &end) << "s" << RESET << std::endl;
    std::cout << YELLOW << "Tempo de sistema: " << t.diffSystemTime(&start, &end) << "s" << RESET << std::endl;

    return finalizaMemLog();
}
