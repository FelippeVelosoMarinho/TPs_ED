//---------------------------------------------------------------------
// Arquivo      : pilha.cpp
// Conteudo     : Implementacao da classe Pilha
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/pilha.hpp"

/**
 * @brief Função para empilhar um item na pilha
 *
 * @param item
 */
void Pilha::Empilha(Point item, int fase)
{
    if (tamanho == MAXTAM)
        throw FullStackException();
    topo++;
    itens[topo] = item;
    tamanho++;
    ESCREVEMEMLOG((long int)&(itens[topo].x), sizeof(int), fase);
    ESCREVEMEMLOG((long int)&(itens[topo].y), sizeof(int), fase);
}

/**
 * @brief Função para desempilhar um item da pilha
 *
 * @return Point
 */
Point Pilha::Desempilha(int fase)
{
    if (tamanho == 0)
        throw EmptyStackException();
    Point aux = itens[topo];
    topo--;
    tamanho--;
    LEMEMLOG((long int)&(itens[topo].x), sizeof(int), fase);
    LEMEMLOG((long int)&(itens[topo].y), sizeof(int), fase);
    return aux;
}

/**
 * @brief Função para limpar a pilha
 *
 */
void Pilha::Limpa()
{
    topo = -1;
    tamanho = 0;
}

/**
 * @brief Função para retornar o segundo item da pilha
 *
 * @return Point
 */
Point Pilha::NextToTop(Pilha S, int fase)
{
    Point p = S.Topo();
    S.Desempilha(fase);
    Point res = S.Topo();
    S.Empilha(p, fase);
    return res;
}

/**
 * @brief Função para ler os pontos de um arquivo
 *
 * @param caminho
 * @param numPoints
 * @return Point*
 */
Point *Pilha::readPoints(const char *caminho, int &numPoints)
{
    FILE *arquivo;
    arquivo = fopen(caminho, "r");

    if (arquivo == NULL)
    {
        throw FileNotFoundException();
    }

    int i = 0;
    char line[100]; // Armazena temporariamente cada linha do arquivo

    // Contar o número de pontos no arquivo
    while (fgets(line, sizeof(line), arquivo) != NULL)
    {
        i++;
    }

    numPoints = i;

    // Alocar a memória corretamente com o tamanho necessário
    Point *points = new Point[numPoints];

    // Voltar ao início do arquivo
    rewind(arquivo);

    i = 0;

    // Ler os pontos do arquivo
    while (fscanf(arquivo, "%d %d", &points[i].x, &points[i].y) != EOF)
    {
        i++;
    }

    fclose(arquivo);

    return points;
}