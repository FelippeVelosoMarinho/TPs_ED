// Arquivo      : program.hpp
// Conteudo     : Classes com as funções principais do programa
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 02/07/2023 - arquivo criado
//-----

#ifndef _PROGRAM_HPP_
#define _PROGRAM_HPP_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sys/resource.h>
#include <fstream>
#include "../include/compress.hpp"
#include "../include/decompress.hpp"
#include "../include/tmp.hpp"

// Definição de cores
#define RESET   "\033[0m"  
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m" 
#define MAGENTA "\033[35m"          
#define CYAN    "\033[36m"      

class Program
{
public:
    int sizeFile(char *caminho); // Função para calcular quantos caracteres tem o arquivo
    unsigned char *readFile(char *caminho); // Função para ler o arquivo
    bool processArguments(int argc, char *argv[], char*& caminho, char*& caminho2, bool& descompactar, bool& compactar); // Função para processar os argumentos
    int sizeFileBytes(char *caminho); // Função para calcular quantos bytes tem o arquivo
    void salvarArquivoDescompactado(unsigned char *texto, char *caminho); // Função para salvar o arquivo descompactado
    void salvarInformacoes(const char *informacoes, char *caminho2); // Função para salvar as informações da compactação
    void salvarTabelaFrequencia(const int* tabela);
    int* carregarTabelaFrequencia();
    int printMenu(int argc, char *argv[]);
};

#endif