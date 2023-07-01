//---------------------------------------------------------------------
// Arquivo      : fibonacci.c
// Conteudo     : programa de avaliação de fibonacci
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 2023-28-03 - arquivo criado
//---------------------------------------------------------------------

#include "../include/fibonacci.h"

int fib_iterativo(int n){
    int i, fibo = 0, fibo1 = 1, fibo2 = 1;
    for(i = 1; i <= n; i++){
        fibo = fibo1 + fibo2;
        fibo1 = fibo2;
        fibo2 = fibo;
    }
    //printf("%d", fibo);
    return fibo;
}

int fib_recursivo(int n){
    if(n == 0 || n == 1){
        return 1;
    }else{
        //printf("%d", fib_recursivo(n - 1) + fib_recursivo(n - 2));
        return fib_recursivo(n - 1) + fib_recursivo(n - 2);
    }
}