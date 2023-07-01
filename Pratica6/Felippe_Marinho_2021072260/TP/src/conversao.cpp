#include "../include/conversao.hpp"

/**
 * @brief Função que converte uma expressão infixa para posfixa
 *
 * @param infixa
 * @param posfixa
 */
void Conversao::converteInfToPos(char infixa[], char posfixa[])
{
    Pilha pilha;
    int j = 0;

    for (int i = 0; infixa[i] != '\0'; i++)
    {
        char c = infixa[i];

        if (c == '(')
        {
            pilha.Empilha(c);
        }
        else if (isdigit(c) || c == '.')
        { // permitir ponto decimal
            posfixa[j++] = c;
        }
        else
        {
            posfixa[j++] = ' '; // adiciona um único espaço separando as expressões
            if (c == '+' || c == '-')
            {
                while (!pilha.Vazia() && pilha.Topo() != '(')
                {
                    posfixa[j++] = pilha.Desempilha(); // desempilha e adiciona na expressão posfixa
                    posfixa[j++] = ' ';                // adiciona um único espaço separando as expressões
                }
                pilha.Empilha(c);
            }
            else if (c == '*' || c == '/')
            {
                while (!pilha.Vazia() && (pilha.Topo() == '*' || pilha.Topo() == '/'))
                {
                    posfixa[j++] = pilha.Desempilha(); // desempilha e adiciona na expressão posfixa
                    posfixa[j++] = ' ';                // adiciona um único espaço separando as expressões
                }
                pilha.Empilha(c);
            }
            else if (c == ')')
            {
                while (!pilha.Vazia() && pilha.Topo() != '(')
                {
                    posfixa[j++] = pilha.Desempilha(); // desempilha e adiciona na expressão posfixa
                    posfixa[j++] = ' ';                // adiciona um único espaço separando as expressões
                }
                if (pilha.Vazia() || pilha.Topo() != '(')
                {
                    throw InvalidExpressionTypeException();
                }
                pilha.Desempilha();
            }
        }
    }

    while (!pilha.Vazia())
    {
        if (pilha.Topo() == '(')
        {
            throw InvalidExpressionTypeException();
        }
        posfixa[j++] = ' '; // adiciona um único espaço separando as expressões
        posfixa[j++] = pilha.Desempilha();
    }

    posfixa[j] = '\0'; // adiciona o caractere nulo no final da expressão posfixa

    std::cout << "Expressão infixa: " << infixa << std::endl;
    std::cout << "Expressão posfixa: " << posfixa << std::endl;
}