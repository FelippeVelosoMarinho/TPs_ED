// Arquivo      : exceptions.hpp
// Conteudo     : Classes de exceções
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//-----

#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

#include <exception>

/**
 * @brief Classe de exceção para arquivo não encontrado
 *
 */
class FillListErrorException : public std::exception
{
public:
    FillListErrorException() {}
    const char *what() const throw()
    {
        return "Erro na alocação da lista!";
    }
};

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
 * @brief Classe de exceção para itens insuficientes na pilha
 *
 */
class InsufficientItemsException : public std::exception
{
public:
    InsufficientItemsException() {}
    const char *what() const throw()
    {
        return "Não há itens suficientes na pilha!";
    }
};

#endif