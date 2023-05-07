//---------------------------------------------------------------------
// Arquivo      : calculadora.cpp
// Conteudo     : Implementacao da classe Calculadora
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 25/04/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/calculadora.hpp"

/**
 * @brief Construtor da classe Calculadora
 *
 */
Calculadora::Calculadora()
{
}

/**
 * @brief Destrutor da classe Calculadora
 *
 */
Calculadora::~Calculadora()
{
}

/**
 * @brief Função para verificar se o caractere é operador
 *
 * @param c Caractere a ser verificado
 * @return '+' ou '-' ou '*' ou '/'
 */
bool Calculadora::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * @brief Função para verificar se o caractere é operando
 *
 * @param c Caractere a ser verificado
 * @return c >= '0' && c <= '9' ou c >= 'a' && c <= 'z' ou c >= 'A' && c <= 'Z'
 */
bool Calculadora::isOperand(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * @brief Função para verificar se a expressão é infixa ou posfixa
 *
 * @param filename Nome do arquivo
 * @param expression Expressão a ser verificada
 * @return 1 se for infixa, 2 se for posfixa e 0 se for inválida
 */
int Calculadora::tipoExpressao(const char *filename, char expression[])
{
    std::ifstream input(filename);

    if (!input.is_open())
    {
        throw FileNotFoundException();
        return 0;
    }
    char line1[1000];
    input.getline(line1, 1000); // Lendo a primeira linha

    int i = 0;
    if (std::strncmp(line1, "LER INFIXA", 10) == 0)
    {
        i = 10;
    }
    else if (std::strncmp(line1, "LER POSFIXA", 11) == 0)
    {
        i = 11;
    }
    else
    {
        // formato inválido]
        throw InvalidExpressionTypeException();
        return 0;
    }

    // Loop para retirar os espaços até o primeiro dígito
    while (line1[i] != '\0' && line1[i] == ' ')
    {
        i++;
    }

    int j = 0;
    while (line1[i] != '\0')
    {
        expression[j] = line1[i];
        i++;
        j++;
    }
    expression[j] = '\0';

    // Verificar o tipo de expressão
    if (std::strncmp(line1, "LER POS", 7) == 0)
    {
        // Posfixa
        return 2;
    }
    else
    {
        // Infixa
        return 1;
    }
}

/**
 * @brief Função para ler a expressão do arquivo e retornar a expressão
 *
 * @param filename Nome do arquivo
 * @param expression Expressão a ser lida
 * @param expression_type Tipo da expressão
 * @param exp_conv Tipo da expressão convertida
 * @return char* Expressão lida
 */
char *Calculadora::lerExpressao(const char *filename, char expression[], int expression_type, int exp_conv)
{
    std::ifstream input(filename);

    if (!input.is_open())
    {
        return nullptr;
    }
    char buffer[1000];
    char line1[1000];
    input.getline(line1, 1000); // Lendo a primeira linha

    int i = 0;
    if (std::strncmp(line1, "LER INFIXA", 10) == 0)
    {
        expression_type = 1;
        i = 10;
    }
    else if (std::strncmp(line1, "LER POSFIXA", 11) == 0)
    {
        expression_type = 2;
        i = 11;
    }
    else
    {
        // formato inválido
        throw InvalidExpressionTypeException();
        return nullptr;
    }

    // Loop para retirar os espaços até o primeiro dígito
    while (line1[i] != '\0' && line1[i] == ' ')
    {
        i++;
    }

    int j = 0;
    while (line1[i] != '\0')
    {
        expression[j] = line1[i];
        i++;
        j++;
    }
    expression[j] = '\0';

    // Verificar o tipo de expressão
    input.getline(buffer, 1000); // Ler tipo de expressão
    input.getline(buffer, 1000); // Descartar terceira linha

    input.close();

    return expression;
}

/**
 * @brief Função para verificar se a expressão infixa é válida
 *
 * @param expr Expressão a ser verificada
 * @return true se for válida e false se for inválida
 */
bool Calculadora::verificaExpressaoInf(char expr[])
{
    int openParens = 0;
    int closeParens = 0;
    int hasOperator = 0;
    int hasOperand = 0;
    int len = strlen(expr);
    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '(')
        {
            openParens++;
        }
        else if (expr[i] == ')')
        {
            closeParens++;
        }
        else if (isdigit(expr[i]))
        {
            hasOperand++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            if (expr[i + 1] != ' ') // verifica se o próximo caractere é um espaço
            {
                throw SpacingErrorException();
                return false;
            }
            hasOperator++;
        }
        else if (expr[i] == ' ')
        {
            continue;
        }
        else if (expr[i] == '.')
        {
            continue;
        }
        else
        {
            // Caractere inválido
            throw InvalidCharacterException();
            return false;
        }
    }

    if (hasOperand < 2)
    {
        throw OperandErrorException();
        return false;
    }
    else if (hasOperator < 1)
    {
        throw OperatorErrorException();
        return false;
    }
    else if (openParens != closeParens)
    {
        throw ParenthesisErrorException();
        return false;
    }
    else
    {
        // Expressão válida
        return true;
    }
}

/**
 * @brief Função para verificar se a expressão posfixa é válida
 *
 * @param expr Expressão a ser verificada
 * @return true se for válida e false se for inválida
 */
bool Calculadora::verificaExpressaoPos(char expr[])
{
    int hasOperator = 0;
    int hasOperand = 0;
    int len = strlen(expr);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(expr[i]))
        {
            hasOperand++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            if (expr[i + 1] != ' ' && expr[i + 1] != expr[len]) // verifica se o próximo caractere é um espaço
            {
                std::cout << "Erro no espaço após um operador: " << expr[i] << std::endl;
                throw SpacingErrorException();
                return false;
            }
            hasOperator++;
        }
        else if (expr[i] == ' ')
        {
            continue;
        }
        else if (expr[i] == '.')
        {
            continue;
        }
        else
        {
            // caractere inválido
            std::cout << "Caractere inválido: " << expr[i] << std::endl;
            throw InvalidCharacterException();
            return false;
        }
    }

    if (hasOperand < 2)
    {
        throw OperandErrorException();
        return false;
    }
    else if (hasOperator < 1)
    {
        throw OperatorErrorException();
        return false;
    }
    else
        return true;
}

/**
 * @brief Função para converter uma expressão infixa para posfixa
 *
 * @param infixa Expressão infixa
 * @param posfixa Expressão posfixa
 * @return char* Expressão posfixa
 */
char *Calculadora::converteInfToPos(char infixa[], char posfixa[])
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
                    posfixa[j++] = pilha.Desempilha();
                    posfixa[j++] = ' ';
                }
                pilha.Empilha(c);
            }
            else if (c == '*' || c == '/')
            {
                while (!pilha.Vazia() && (pilha.Topo() == '*' || pilha.Topo() == '/'))
                {
                    posfixa[j++] = pilha.Desempilha();
                    posfixa[j++] = ' ';
                }
                pilha.Empilha(c);
            }
            else if (c == ')')
            {
                while (!pilha.Vazia() && pilha.Topo() != '(')
                {
                    posfixa[j++] = pilha.Desempilha();
                    posfixa[j++] = ' ';
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
        posfixa[j++] = ' ';
        posfixa[j++] = pilha.Desempilha();
    }

    posfixa[j] = '\0';

    return posfixa;
}

Pilha Calculadora::convertePraPos(char infixa[])
{
    Pilha pilha_posfixa;
    Pilha pilha_operadores;

    for (int i = 0; infixa[i] != '\0'; i++)
    {
        char c = infixa[i];

        if (c == '(')
        {
            pilha_operadores.Empilha(c);
        }
        else if (isdigit(c) || c == '.')
        {
            // Converte o caractere para um número float e empilha na pilha_posfixa
            float num = atof(&infixa[i]);
            pilha_posfixa.Empilha(num);

            // Incrementa o índice para pular o número na próxima iteração
            while (isdigit(infixa[i]) || infixa[i] == '.')
            {
                i++;
            }
            i--; // Decrementa para compensar a iteração do loop
        }
        else
        {
            if (c == '+' || c == '-')
            {
                while (!pilha_operadores.Vazia() && pilha_operadores.Topo() != '(')
                {
                    char op = pilha_operadores.Desempilha();
                    pilha_posfixa.Empilha(op);
                }
                pilha_operadores.Empilha(c);
            }
            else if (c == '*' || c == '/')
            {
                while (!pilha_operadores.Vazia() && (pilha_operadores.Topo() == '*' || pilha_operadores.Topo() == '/'))
                {
                    char op = pilha_operadores.Desempilha();
                    pilha_posfixa.Empilha(op);
                }
                pilha_operadores.Empilha(c);
            }
            else if (c == ')')
            {
                while (!pilha_operadores.Vazia() && pilha_operadores.Topo() != '(')
                {
                    char op = pilha_operadores.Desempilha();
                    pilha_posfixa.Empilha(op);
                }
                if (pilha_operadores.Vazia())
                {
                    throw InvalidExpressionTypeException();
                }
                pilha_operadores.Desempilha(); // Remove o '(' da pilha
            }
        }
    }

    while (!pilha_operadores.Vazia())
    {
        char op = pilha_operadores.Desempilha();
        if (op == '(')
        {
            throw InvalidExpressionTypeException();
        }
        pilha_posfixa.Empilha(op);
    }

    return pilha_posfixa;
}

/**
 * @brief Função para converter uma expressão posfixa para infixa
 *
 * @param posfixa Expressão posfixa
 * @return char* Expressão infixa
 */
char *Calculadora::convertePostoInf(char posfixa[])
{
    Pilha p;
    int tam = strlen(posfixa);
    char c, op1, op2;
    char *expressao = new char[2 * tam + 1];
    int i = 0;

    for (int j = 0; j < tam; j++)
    {
        c = posfixa[j];
        if (isOperand(c) || c == '.')
        {
            expressao[i++] = c;
            expressao[i++] = ' '; // adiciona um espaço em branco após o operando
            p.Empilha(c);
        }
        else
        {
            op2 = p.Desempilha();
            op1 = p.Desempilha();
            expressao[i++] = '(';
            expressao[i++] = op1;
            expressao[i++] = ' '; // adiciona um espaço em branco após o operando 1
            expressao[i++] = c;
            expressao[i++] = ' '; // adiciona um espaço em branco após o operador
            expressao[i++] = op2;
            expressao[i++] = ' '; // adiciona um espaço em branco após o operando 2
            expressao[i++] = ')';
            p.Empilha(expressao[i - 9]); // empilha a subexpressão criada
        }
    }
    expressao[i] = '\0';

    return expressao;
}

/**
 * @brief Função para calcular uma expressão posfixa
 *
 * @param expr Expressão posfixa
 * @return float Resultado da posfixa
 */
float Calculadora::calculaPos(char *expr)
{
    if (!verificaExpressaoPos(expr))
    {
        std::cout << "Expressão inválida pos!" << std::endl;
        throw "Expressão inválida pos!";
    }
    else
    {
        Pilha p;
        int len = strlen(expr);
        float op1, op2, result;
        char token[30];

        for (int i = 0; i < len; i++)
        {
            if (isdigit(expr[i]) || expr[i] == '.')
            {
                const char *pstr = expr + i; // define um ponteiro para o início do número
                char *pEnd;                  // ponteiro que será atualizado pela função strtod
                double num = strtod(pstr, &pEnd);
                int n = pEnd - pstr;         // número de caracteres lidos na conversão
                i += n - 1;                  // atualiza o índice i para pular os caracteres já lidos
                sprintf(token, "%.6f", num); // formata o número com precisão em 6 casas decimais
                num = atof(token);           // converte o número de volta para float com a precisão desejada
                // std::cout << "token: " << token << std::endl; // printa o token formatado
                // std::cout << "Número: " << num << std::endl;
                p.Empilha(num);
            }
            else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            {
                op2 = p.Desempilha();
                op1 = p.Desempilha();

                switch (expr[i])
                {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0)
                        throw DivisaoPorZeroException();
                    result = op1 / op2;
                    break;
                default:
                    std::cout << "Operador inválido: " << expr[i] << std::endl;
                    return 0;
                }
                sprintf(token, "%.6f", result); // formata o resultado com precisão em 6 casas decimais
                result = atof(token);           // converte o resultado de volta para float com a precisão desejada
                p.Empilha(result);
            }
        }
        return p.Desempilha();
    }
}

/**
 * @brief Função para calcular uma expressão infixa
 *
 * @param expr Expressão infixa
 * @return float Resultado da infixa
 */
float Calculadora::calculaInf(char expr[])
{
    Pilha pilha;

    // Monta a árvore a partir da expressão infixa
    int i = 0;
    while (expr[i] != '\0')
    {
        if (isdigit(expr[i]) || expr[i] == '.' || expr[i] == ' ') // Se o caractere é um dígito ou um ponto decimal, adiciona o número na pilha
        {
            float num = 0;
            int decimal_places = 0;
            while (isdigit(expr[i]) || expr[i] == '.' || expr[i] == ' ') // Lê o número completo
            {
                if (expr[i] == '.' && num == 0) // verifica se o número começa com um ponto decimal
                    throw std::invalid_argument("Numero invalido");
                if (expr[i] == '.') // conta o número de casas decimais
                    decimal_places++;
                if (decimal_places > 1) // verifica se o número tem mais de uma casa decimal
                    throw std::invalid_argument("Numero invalido");
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            pilha.Empilha(num);
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') // Se o caractere é um operador, desempilha dois números e realiza a operação
        {
            float op2 = pilha.Desempilha();
            float op1 = pilha.Desempilha();
            float res;
            switch (expr[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                if (op2 == 0) // Verifica se a divisão por zero é inválida
                    throw std::invalid_argument("Divisao por zero");
                res = op1 / op2;
                break;
            }
            pilha.Empilha(res);
            i++;
        }
        else // Ignora outros caracteres
        {
            i++;
        }
    }

    // O resultado é o único valor restante na pilha de valores
    return pilha.Topo();
}

/**
 * @brief Função para resolver a expressão utilizando as funções acima
 *
 * @param filename
 * @param expression
 * @param expression_type
 * @param exp_conv
 */
void Calculadora::resolveExpressao(const char *filename, char expression[], int expression_type, int exp_conv)
{
    Pilha p;

    char expr[1000];
    // Nessa expressão será pego a expressão lida em lerExpressao, verifica a expressao
    if (tipoExpressao(filename, expr) == 1)
    {
        // verifica a expressao
        if (verificaExpressaoInf(lerExpressao(filename, expr, expression_type, exp_conv)))
        {
            // std::cout << "Conversão através da pilha" << p.ImprimePilha(convertePraPos(lerExpressao(filename, expression, expression_type, exp_conv))) << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Expressão Infixa Válida: " << lerExpressao(filename, expr, expression_type, exp_conv) << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Expressão convertida para Posfixa: " << converteInfToPos(lerExpressao(filename, expr, expression_type, exp_conv), expr) << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Resultado da operação: " << calculaInf(lerExpressao(filename, expr, expression_type, exp_conv)) << std::endl;
            return;
        }
        else
        {
            throw InvalidInfixException();
            return;
        }
    }
    else if (tipoExpressao(filename, expr) == 2)
    {
        if (verificaExpressaoPos(lerExpressao(filename, expr, expression_type, exp_conv)))
        {
            std::cout << "Expressão Posfixa Válida: " << lerExpressao(filename, expr, expression_type, exp_conv) << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Expressão convertida para Infixa: " << convertePostoInf(lerExpressao(filename, expr, expression_type, exp_conv)) << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Resultado da operação: " << calculaPos(lerExpressao(filename, expr, expression_type, exp_conv)) << std::endl;
            return;
        }
        else
        {
            throw InvalidInfixException();
            return;
        }
    }
    else
    {
        throw InvalidExpressionTypeException();
    }
}
