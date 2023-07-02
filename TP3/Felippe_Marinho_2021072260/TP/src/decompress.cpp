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
 * @brief Função para descomprimir o texto
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
 * @brief Função para descompactar o arquivo
 *
 * @param root
 */
void Decompress::descompact(Node *root)
{
    FILE *arq = fopen("compactado.wg", "rb"); // Arquivo binário
    Node *aux = root;
    unsigned char byte;
    int i;

    if (arq)
    {
        while (fread(&byte, sizeof(unsigned char), 1, arq))
        {
            for (i = 7; i >= 0; i--)
            {
                if (isBitOne(byte, i))
                {
                    aux = aux->dir;
                }
                else
                {
                    aux = aux->esq;
                }
                if (aux->esq == NULL && aux->dir == NULL)
                {
                    std::cout << aux->caracter; // depois mudar para escrever no arquivo
                    aux = root; // volta para a raiz
                }
            }
        }
        fclose(arq);
    }
    else
    {
        throw FileNotFoundException();
    }
}