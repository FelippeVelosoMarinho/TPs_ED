#include <iostream>
#include "../include/functions.hpp"
#include "../include/conversao.hpp"
#include "../include/memlog.hpp"

/**
 * @brief Função principal do programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    char *lognome;
    if (argc > 1)
    {
        lognome = argv[1];
    }
    else
    {
        std::cerr << "Uso: " << argv[0] << " <caminho do arquivo>" << std::endl;
        return 1;
    }
    iniciaMemLog(lognome);
    ativaMemLog();
    Functions f;
    struct rusage start, end; // Structs para medir o tempo de execução
    //memlog ml; // Objeto para medir o uso de memória
    srand(time(NULL));

    // Gerando um array de 1000 elementos aleatórios
    Conversao c;
    char infixa[1000] = "( ( ( ( 9.904341 ) + ( ( 5.733451 ) - ( 0.641665 ) ) ) - ( ( 2.165881 ) + ( 1.404730 ) ) ) - ( ( 5.732986 ) + ( ( 5.938726 ) - ( 8.993233 ) ) ) )";
    char posfixa[1000];
    
    defineFaseMemLog(0);
    getrusage(RUSAGE_SELF, &start);
    std::cout << "----------" << std::endl;
    std::cout << "Conversão da infixa pra pos" << std::endl;
    c.converteInfToPos(infixa, posfixa);
    getrusage(RUSAGE_SELF, &end);
    
    printf("Tempo de usuário: %f\n", f.diffUserTime(&start, &end));
    printf("Tempo de sistema: %f\n", f.diffSystemTime(&start, &end));


    return finalizaMemLog();
}