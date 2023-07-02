// Arquivo      : compress.cpp
// Conteudo     : Implementação da classe da compressão
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 01/07/2023 - arquivo criado
//-----

#include "../include/compress.hpp"

/**
 * @brief Construtor da classe Compress
 *
 */
Compress::Compress()
{
    this->fileInput = NULL;
    this->fileOutput = NULL;
    this->dictionary = NULL;
    this->sizeDictionary = 0;
}

/**
 * @brief Destrutor da classe Compress
 *
 */
Compress::~Compress()
{
    if (this->fileInput != NULL)
    {
        delete[] this->fileInput;
    }
    if (this->fileOutput != NULL)
    {
        delete[] this->fileOutput;
    }
    if (this->dictionary != NULL)
    {
        for (int i = 0; i < this->sizeDictionary; i++)
        {
            if (this->dictionary[i] != NULL)
            {
                delete[] this->dictionary[i];
            }
        }
        delete[] this->dictionary;
    }
}

/**
 * @brief Função para calcular o tamanho da string
 *
 * @param dictionary
 * @param string
 * @return int
 */
int Compress::stringSize(char **dictionary, unsigned char *string)
{
    int i = 0, size = 0;
    while (string[i] != '\0')
    {
        size += strlen(dictionary[string[i]]);
        i++;
    }
    return size + 1;
}

/**
 * @brief Função para comprimir a string
 *
 * @param dictionary
 * @param string
 * @return char*
 */
char *Compress::compress(char **dictionary, unsigned char *string)
{
    int i = 0, j = 0, k = 0, size = 0;
    char *stringCompressed = NULL;
    while (string[i] != '\0')
    {
        size += strlen(dictionary[string[i]]);
        i++;
    }
    stringCompressed = new char[size + 1];
    i = 0;
    while (string[i] != '\0')
    {
        j = 0;
        while (dictionary[string[i]][j] != '\0')
        {
            stringCompressed[k] = dictionary[string[i]][j];
            j++;
            k++;
        }
        i++;
    }
    stringCompressed[k] = '\0';
    return stringCompressed;
}

/**
 * @brief Função para compactar o arquivo
 *
 * @param caminho
 */
void Compress::compact(unsigned char *caminho)
{
    FILE *arq = fopen("compactado.wg", "wb"); // Arquivo binário
    int i = 0, j = 7;
    unsigned char mask, byte = 0; // 00000000
    if (arq)
    {
        while (caminho[i] != '\0')
        {
            mask = 1;
            if (caminho[i] == '1')
            {
                mask = mask << j;
                byte = byte | mask;
            }
            j--;
            if (j < 0) // byte cheio
            {
                fwrite(&byte, sizeof(unsigned char), 1, arq);
                j = 7;
                byte = 0;
            }
            i++;
        }
        if (j != 7) // byte não cheio
        {
            fwrite(&byte, sizeof(unsigned char), 1, arq);
        }
        fclose(arq);
    }
    else
    {
        throw FileNotFoundException();
    }
}