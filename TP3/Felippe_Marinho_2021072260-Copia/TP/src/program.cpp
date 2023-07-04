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
    int tamanho = this->sizeFile(caminho);

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        throw FileNotFoundException();
    }

    texto = (unsigned char *)malloc(tamanho + 1); // +1 para o caractere nulo

    if (texto == NULL)
    {
        fclose(arq);
        throw MemoryAllocationException();
    }

    int i = 0;
    int c;

    while ((c = fgetc(arq)) != EOF)
    {
        texto[i] = (unsigned char)c;
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
 * @param caminho2
 * @param descompactar
 * @param compactar
 * @return bool
 */
bool Program::processArguments(int argc, char *argv[], char *&caminho, char *&caminho2, bool &descompactar, bool &compactar)
{
    if (argc > 3)
    {
        caminho = argv[1];
        caminho2 = argv[2];

        for (int i = 3; i < argc; i++)
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
 * @brief Função que salva um arquivo contendo o texto descompactado em um arquivo txt
 *
 * @param caminho
 * @param texto
 */
void Program::salvarArquivoDescompactado(unsigned char *texto, char *caminho2)
{
    // FILE *arq = fopen("descompactado.txt", "w"); // Arquivo txt
    FILE *arq = fopen(caminho2, "w"); // Arquivo txt
    int i = 0;

    while (texto[i] != '\0')
    {
        fputc(texto[i], arq);
        i++;
    }

    std::cout << GREEN << "√ Arquivo descompactado em '" << caminho2 << "'" << RESET << std::endl;
    fclose(arq);
}

/**
 * @brief Função que salva as informações da compactação em um arquivo txt
 *
 * @param informacoes
 * @param caminho
 */
void Program::salvarInformacoes(const char *informacoes, char *caminho)
{
    FILE *arq = fopen(caminho, "w"); // Arquivo txt

    if (arq)
    {
        fprintf(arq, "%s", informacoes); // Escreve as informações no arquivo
        fclose(arq);
        std::cout << GREEN << "√ Informações da compactação salvas em '" << caminho << "'" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "X Erro ao salvar as informações da compactação" << RESET << std::endl;
        throw FileErrorException();
    }
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
        fwrite(tabela, sizeof(int), MAX_SIZE, arq); // Escreve a tabela de frequência no arquivo
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
 * @brief Função para carregar a tabela de frequência de um arquivo binário
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
    char *caminho2;
    bool descompactar = false;
    bool compactar = false;

    struct rusage start, end; // Structs para medir o tempo de execução

    if (!this->processArguments(argc, argv, caminho, caminho2, descompactar, compactar))
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo 1> <caminho do arquivo 2> [-c] [-d]" << std::endl;
        return 1;
    }
    // Chame uma função para gerar os gráficos usando a memlog aqui
    std::cout << GREEN << "√ Log gerado em './tmp/huffmanLog.out'" << RESET << std::endl;
    char *lognome = "./tmp/huffmanLog.out";
    iniciaMemLog(lognome);
    ativaMemLog();

    // Define a fase 0 do memlog
    defineFaseMemLog(0);
    // Inicializa o contador de pontos
    getrusage(RUSAGE_SELF, &start);

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
        comp->compact((unsigned char *)cod, caminho2);
        std::cout << GREEN << "√ Arquivo compactado gerado em '" << caminho2 << "'" << RESET << std::endl;

        beforeSize = this->sizeFileBytes(caminho); // Tamanho do arquivo original
        // afterSize = this->sizeFileBytes("./compactado.wg"); // Tamanho do arquivo compactado
        afterSize = this->sizeFileBytes(caminho2); // Tamanho do arquivo compactado
        std::cout << CYAN << "\n --- Informações da compactação ---" << RESET << std::endl;
        std::cout << MAGENTA << "De " << beforeSize << " bytes para " << afterSize << " bytes..." << RESET << std::endl;
        std::cout << MAGENTA << "Fator de compressão: " << (float)beforeSize / afterSize << RESET << std::endl;
        std::cout << MAGENTA << "Taxa de compressão: " << (float)afterSize / beforeSize * 100 << "%\n"
                  << RESET << std::endl;

        // criar um array de char com as informações da compactação
        /*std::string informacoes = "Tamanho do arquivo original: " + std::to_string(beforeSize) + " bytes\n";
        informacoes += "Tamanho do arquivo compactado: " + std::to_string(afterSize) + " bytes\n";
        informacoes += "Fator de compressão: " + std::to_string((float)beforeSize / afterSize) + "\n";
        informacoes += "Taxa de compressão: " + std::to_string((float)afterSize / beforeSize * 100) + "%\n";

        this->salvarInformacoes(informacoes.c_str(), caminho2); // Salva as informações da compactação em um txt*/

        std::cout << GREEN << "\nPara descompactar agora, digite: " << RESET << std::endl;
        std::cout << YELLOW << " ----- ./bin/main 'COMPACTADO.wg' 'DESCOMPACTADO.txt' -d ----- " << RESET << std::endl;

        free(texto);
        dic->freeDictionary(dictionary, columns);
    }

    // Descompactar o texto
    if (descompactar)
    {
        unsigned char *textoDescompactado = decomp->descompactar(caminho);

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

        this->salvarArquivoDescompactado((unsigned char *)decod, caminho2); // Salva o arquivo descompactado em um txt

        free(textoDescompactado);
        free(tabela);
        dic->freeDictionary(dictionary, columns);
    }

    // Libera a memória alocada
    // delete texto;
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
