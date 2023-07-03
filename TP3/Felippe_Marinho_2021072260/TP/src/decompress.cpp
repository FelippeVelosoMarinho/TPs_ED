// Arquivo      : decompress.cpp
// Conteudo     : Implementação da classe da descompressão
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#include "../include/decompress.hpp"

/**
 * @brief Construtor da classe Decompress
 *
 */
Decompress::Decompress()
{
}

/**
 * @brief Destrutor da classe Decompress
 *
 */
Decompress::~Decompress()
{
}

/**
 * @brief Função para descodificar o texto
 *
 * @param texto
 * @param root
 * @return char*
 */
char *Decompress::decompress(unsigned char *texto, Node *root)
{
    int i = 0;
    Node *aux = root;
    char temp[2];
    char *decompress = (char *)calloc(strlen((const char *)texto), sizeof(char));

    while (texto[i] != '\0')
    {
        if (texto[i] == '0')
        {
            aux = aux->esq;
        }
        else
        {
            aux = aux->dir;
        }
        if (aux->esq == NULL && aux->dir == NULL)
        {
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decompress, temp);
            aux = root;
        }
        i++;
    }

    return decompress;
}

/**
 * @brief Função para verificar se o bit é 1
 *
 * @param byte
 * @param pos
 * @return unsigned int
 */
unsigned int Decompress::isBitOne(unsigned char byte, int pos)
{
    unsigned char mask = (1 << pos);
    return byte & mask;
}

/**
 * @brief Função para descompactar o arquivo previamente compactado, recebe como parâmetro o caminho de uma arquivo txt vazio para ser preenchido com o texto descompactado
 *
 * @return unsigned*
 */
unsigned char *Decompress::descompactar()
{
    FILE *arq = fopen("compactado.wg", "rb"); // Arquivo binário
    unsigned char byte;
    int i;
    int bufferSize = 0;
    unsigned char *auxChar = nullptr;

    if (arq)
    {
        // Determinar o tamanho necessário para o buffer
        while (fread(&byte, sizeof(unsigned char), 1, arq))
        {
            bufferSize += 8;
        }
        fclose(arq);

        // Alocar o buffer com o tamanho necessário
        auxChar = new unsigned char[bufferSize + 1];
        auxChar[bufferSize] = '\0'; // Definir o caractere nulo de terminação

        arq = fopen("compactado.wg", "rb"); // Reabrir o arquivo

        if (arq)
        {
            int index = 0;

            while (fread(&byte, sizeof(unsigned char), 1, arq))
            {
                for (i = 7; i >= 0; i--)
                {
                    if (isBitOne(byte, i))
                    {
                        auxChar[index] = '1';
                    }
                    else
                    {
                        auxChar[index] = '0';
                    }
                    index++;
                }
            }
            fclose(arq);
        }
        else
        {
            delete[] auxChar; // Liberar a memória alocada em caso de erro
            throw FileNotFoundException();
        }
    }
    else
    {
        throw FileNotFoundException();
    }

    return auxChar;
}
