// Arquivo      : exceptions.hpp
// Conteudo     : Classes de exceções
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 09/05/2023 - arquivo criado
//-----

#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

#include <exception>

/**
 * @brief Classe de exceção para arquivo não encontrado
 *
 */
class FileNotFoundException : public std::exception
{
public:
    FileNotFoundException() {}
    const char *what() const throw()
    {
        return "Erro na abertura do arquivo!";
    }
};

/**
 * @brief Classe de exceção para pilha vazia
 *
 */
class EmptyStackException : public std::exception
{
public:
    EmptyStackException() {}
    const char *what() const throw()
    {
        return "Pilha vazia!";
    }
};

/**
 * @brief Classe de exceção para pilha cheia
 *
 */
class FullStackException : public std::exception
{
public:
    FullStackException() {}
    const char *what() const throw()
    {
        return "Pilha cheia!";
    }
};

/**
 * @brief Classe de exceção para divisão por zero
 *
 */
class DivisaoPorZeroException : public std::exception
{
public:
    DivisaoPorZeroException() {}
    const char *what() const throw()
    {
        return "Divisao por zero!";
    }
};

/**
 * @brief Classe de exceção para expressão posfixa inválida
 *
 */
class InvalidPostfixException : public std::exception
{
public:
    InvalidPostfixException() {}
    const char *what() const throw()
    {
        return "Expressao pos-fixa invalida!";
    }
};

/**
 * @brief Classe de exceção para expressão infixa inválida
 *
 */
class InvalidInfixException : public std::exception
{
public:
    InvalidInfixException() {}
    const char *what() const throw()
    {
        return "Expressao infixa invalida!";
    }
};

/**
 * @brief Classe de exceção para o tipo de expressão não é válida(infixa ou posfixa)
 *
 */
class InvalidExpressionTypeException : public std::exception
{
public:
    InvalidExpressionTypeException() {}
    const char *what() const throw()
    {
        return "Tipo de expressao invalido!";
    }
};

/**
 * @brief Classe de exceção para erros no operador
 *
 */
class OperatorErrorException : public std::exception
{
public:
    OperatorErrorException() {}
    const char *what() const throw()
    {
        return "Operador invalido!";
    }
};

/**
 * @brief Classe de exceção para erros no operando
 *
 */
class OperandErrorException : public std::exception
{
public:
    OperandErrorException() {}
    const char *what() const throw()
    {
        return "Operando invalido!";
    }
};

/**
 * @brief Classe de exceção para erros no parenteses
 *
 */
class ParenthesisErrorException : public std::exception
{
public:
    ParenthesisErrorException() {}
    const char *what() const throw()
    {
        return "Parenteses invalido!";
    }
};

/**
 * @brief Classe de exceção para erros no caractere
 *
 */
class InvalidCharacterException : public std::exception
{
public:
    InvalidCharacterException() {}
    const char *what() const throw()
    {
        return "Caractere invalido!";
    }
};

/**
 * @brief Classe de exceção para erros no espaçamento
 *
 */
class SpacingErrorException : public std::exception
{
public:
    SpacingErrorException() {}
    const char *what() const throw()
    {
        return "Erro no espacamento!";
    }
};

#endif