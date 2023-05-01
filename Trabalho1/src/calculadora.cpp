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
        // formato inválido
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
        //std::cout << "Do tipo posfixa" << std::endl;
        return 2;
    }
    else
    {
        //std::cout << "Do tipo infixa" << std::endl;
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
    std::cout << "Entrou na leitura" << std::endl;
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
    // std::cout<<len<<std::endl;
    for (int i = 0; i < len; i++)
    {
        // std::cout<<"TESTS: "<<expr[i]<<std::endl;
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
            // std::cout << expr[i] << std::endl;
            hasOperand++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            if (expr[i + 1] != ' ') // verifica se o próximo caractere é um espaço
            {
                std::cout << "Erro no espaço após um operador" << std::endl;
                return false;
            }
            // std::cout << expr[i] << std::endl;
            hasOperator++;
        }
        else if (expr[i] == ' ')
        {
            // std::cout << "Espaço" << std::endl;
            continue;
        }
        else if (expr[i] == '.')
        {
            // std::cout << expr[i] << std::endl;
            continue;
        }
        else
        {
            // invalid character
            std::cout << "Caractere inválido: " << expr[i] << std::endl;
            return false;
        }
    }

    if (hasOperand < 2)
    {
        std::cout << "Erro no operando" << std::endl;
        return false;
    }
    else if (hasOperator < 1)
    {
        std::cout << "Erro no operador" << std::endl;
        return false;
    }
    else if (openParens != closeParens)
    {
        std::cout << "Erro no parêntese" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Expressão válida" << std::endl;
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
            return false;
        }
    }

    if (hasOperand < 2)
    {
        std::cout << "Erro no operando" << std::endl;
        return false;
    }
    else if (hasOperator < 1)
    {
        std::cout << "Erro no operador" << std::endl;
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
char *Calculadora::converteInf(char infixa[], char posfixa[])
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
                    throw "Expressão inválida!";
                }
                pilha.Desempilha();
            }
        }
    }

    while (!pilha.Vazia())
    {
        if (pilha.Topo() == '(')
        {
            throw "Expressão inválida!";
        }
        posfixa[j++] = ' ';
        posfixa[j++] = pilha.Desempilha();
    }

    posfixa[j] = '\0';

    // imprimir expressão posfixa formatada
    std::cout << "Expressão convertida: ";
    // Percorrer o array posfixa e retirar os espaços desnecessários
    /* for (int i = 0; i < j; i++)
     {
         if (posfixa[i] == ' ' && posfixa[i + 1] == ' ')
         {
             continue;
         }
         else
         {
             std::cout << posfixa[i];
         }
     }
     std::cout << std::endl;*/

    std::cout << posfixa << std::endl;

    return posfixa;
}

/**
 * @brief Função para converter uma expressão posfixa para infixa
 * 
 * @param posfixa Expressão posfixa
 * @param infixa Expressão infixa
 * @return char* Expressão infixa
*/
char *Calculadora::convertePos(char infixa[], char posfixa[])
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
                    throw "Expressão inválida!";
                }
                pilha.Desempilha();
            }
        }
    }

    while (!pilha.Vazia())
    {
        if (pilha.Topo() == '(')
        {
            throw "Expressão inválida!";
        }
        posfixa[j++] = ' ';
        posfixa[j++] = pilha.Desempilha();
    }

    posfixa[j] = '\0';

    std::cout << "Expressão convertida agora: " << infixa << std::endl;
    return posfixa;
}

/**
 * @brief Função para calcular uma expressão posfixa
 * 
 * @param expr Expressão posfixa
 * @return float Resultado da posfixa
*/
float Calculadora::calculaPos(char *expr)
{
    std::cout << "Entrou no calcula Pos" << std::endl;
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
        char token[20];

        for (int i = 0; i < len; i++)
        {
            if (isdigit(expr[i]) || expr[i] == '.')
            {
                int j = 0;
                while (isdigit(expr[i]) || expr[i] == '.')
                {
                    token[j++] = expr[i++];
                }
                token[j] = '\0';
                float num = atof(token);
                snprintf(token, 20, "%.6f", num); // formata o número com precisão em 6 casas decimais
                num = atof(token);                // converte o número de volta para float com a precisão desejada
                std::cout << "num: " << num << std::endl;
                p.Empilha(num);
            }
            else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            {
                op2 = p.Desempilha();
                op1 = p.Desempilha();
                // std::cout << "op1: " << op1 << " " << expr[i] << " op2: " << op2 << std::endl;

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
                    result = op1 / op2;
                    break;
                default:
                    std::cout << "Operador inválido: " << expr[i] << std::endl;
                    return 0;
                }
                snprintf(token, 20, "%.6f", result); // formata o resultado com precisão em 6 casas decimais
                result = atof(token);                // converte o resultado de volta para float com a precisão desejada
                p.Empilha(result);
            }
        }
        return p.Desempilha();
    }
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
    char expr[1000];
    // Nessa expressão será pego a expressão lida em lerExpressao, verifica a expressao
    if (tipoExpressao(filename, expr) == 1)
    {
        //verifica a expressao
        if (verificaExpressaoInf(lerExpressao(filename, expr, expression_type, exp_conv)))
        {
            std::cout << "Expressão infixa" << std::endl;
            std::cout << "Resultado infixa: " << 
            calculaPos(converteInf(lerExpressao(filename, expr, expression_type, exp_conv), expr)) << std::endl;
            return;
        }
        else
        {
            std::cout << "Expressão infixa inválida" << std::endl;
            return;
        }
    }
    else if (tipoExpressao(filename, expr) == 2)
    {
        if (verificaExpressaoPos(lerExpressao(filename, expr, expression_type, exp_conv)))
        {
            std::cout << "Expressão posfixa" << std::endl;
            std::cout << "Resultado posfixa: " << calculaPos(lerExpressao(filename, expr, expression_type, exp_conv)) << std::endl;
            return;
        }
        else
        {
            std::cout << "Expressão posfixa inválida" << std::endl;
            return;
        }
    }
    else
    {
        std::cout << "Expressão inválida" << std::endl;
    }
}
