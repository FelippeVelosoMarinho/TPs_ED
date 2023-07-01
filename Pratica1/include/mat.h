//---------------------------------------------------------------------
// Arquivo	: mat.h
// Conteudo	: definicoes do TAD MATRIZ
// Autor	: Felippe Veloso Marinho (felippe.veloso15@gmail.com)
// Historico	: 2023-21-03 - arquivo criado
//---------------------------------------------------------------------

#ifndef MAT
#define MAT
#include <stdio.h>

#define MAXTAM 5

typedef struct mat{
	double m[MAXTAM][MAXTAM];
	int tamx, tamy;
	int id;
} mat_tipo;

// definicoes de operacoes a serem testadas
#define OPSOMAR 1
#define OPMULTIPLICAR 2
#define OPTRANSPOR 3
#define OPCRIAR 4

// limite superior da inicializacao aleatoria
#define INITRANDOMRANGE 10
// Macro que realiza swap sem variavel auxiliar
#define ELEMSWAP(x,y) (x+=y,y=x-y,x-=y)

void criaMatriz(mat_tipo * mat, int tx, int ty, int id);
// Descricao: cria matriz com dimensoes tx X ty
// Entrada: mat, tx, ty, id
// Saida: mat

void inicializaMatrizNula(mat_tipo * mat);
// Descricao: inicializa mat com valores nulos 
// Entrada: mat
// Saida: mat

void inicializaMatrizAleatoria(mat_tipo * mat);
// Descricao: inicializa mat com valores aleatorios
// Entrada: mat 
// Saida: mat

double acessaMatriz(mat_tipo * mat);
// Descricao: acessa mat para fins de registro de acesso 
// Entrada: mat 
// Saida: mat

void imprimeMatriz(mat_tipo * mat);
// Descricao: imprime a matriz com a identificacao de linhas e colunas
// Entrada: mat
// Saida: impressao na saida padrao (stdout) 

void salvaMatriz(mat_tipo * mat, FILE * out);
// Descricao: salva a matriz em arquivo
// Entrada: mat
// Saida: out

void escreveElemento(mat_tipo * mat, int x, int y, double v);
// Descricao: atribui o valor v ao elemento (x,y) de mat
// Entrada: mat, x, y, v
// Saida: mat

double leElemento (mat_tipo * mat, int x, int y);
// Descricao: retorna o elemento (x,y) de mat 
// Entrada: mat, x, y
// Saida: mat[x][y] 

void copiaMatriz(mat_tipo *src, mat_tipo * dst, int dst_id);
// Descricao: faz uma copia de src em dst
// Entrada: src, dst_id
// Saida: dst

void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);
// Descricao: soma as matrizes a e b e armazena o resultado em c
// Entrada: a, b
// Saida: c

void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);
// Descricao: multiplica as matrizes a e b e armazena o resultado em c
// Entrada: a,b
// Saida: c

void transpoeMatriz(mat_tipo *a);
// Descricao: transpoe a matriz a
// Entrada: a
// Saida: a

void destroiMatriz(mat_tipo *a);
// Descricao: destroi a matriz a, que se torna inacessível
// Entrada: a
// Saida: a

void uso();
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando

#endif