// Arquivo      : exceptions.hpp
// Conteudo     : Classes de exceções
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 30/06/2023 - arquivo criado
//-----

#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

#include <exception>

/**
 * @brief Classe de exceção para erro na escrita ou leitura do arquivo
 * 
 */
class FileErrorException : public std::exception
{
public:
    FileErrorException() {}
    const char *what() const throw()
    {
        return "Erro na escrita ou leitura do arquivo!";
    }
};

/**
 * @brief Classe de exceção para erro na compressão
 *
 */
class CompressionErrorException : public std::exception
{
public:
    CompressionErrorException() {}
    const char *what() const throw()
    {
        return "Erro na compressão!";
    }
};

/**
 * @brief Classe de exceção para erro na descompressão
 *
 */
class DecompressionErrorException : public std::exception
{
public:
    DecompressionErrorException() {}
    const char *what() const throw()
    {
        return "Erro na descompressão!";
    }
};

/**
 * @brief Classe de exceção para arquivo não encontrado
 *
 */
class AllocationErrorException : public std::exception
{
public:
    AllocationErrorException() {}
    const char *what() const throw()
    {
        return "Erro na alocação!";
    }
};

/**
 * @brief Classe de exceção de lista vazia
 *
 */
class EmptyListException : public std::exception
{
public:
    EmptyListException() {}
    const char *what() const throw()
    {
        return "Lista vazia!";
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

#endif