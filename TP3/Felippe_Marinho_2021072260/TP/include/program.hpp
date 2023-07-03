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
#include "../include/memlog.hpp"
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
    unsigned char *readFile(char *caminho);
    bool processArguments(int argc, char *argv[], char*& caminho, bool& descompactar, bool& compactar);
    int sizeFileBytes(char *caminho); // Função para calcular quantos bytes tem o arquivo
    void salvarArquivo(unsigned char *texto); // Função auxiliar que salva um arquivo contendo o texto original em um arquivo txt
    void salvarArquivoDescompactado(unsigned char *texto); 
    void salvarTabelaFrequencia(const int* tabela);
    int* carregarTabelaFrequencia();
    int printMenu(int argc, char *argv[]);
};

#endif