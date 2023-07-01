//---------------------------------------------------------------------
// Arquivo      : arvore.cpp
// Conteudo     : Implementacao da classe Arvore
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 07/05/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/arvore.hpp"

No::No()
{
    esq = NULL;
    dir = NULL;
}

No::~No()
{
    esq = NULL;
    dir = NULL;
}

Arvore::Arvore()
{
    raiz = NULL;
}

Arvore::~Arvore()
{
    Limpa();
}

void Arvore::Insere(char item)
{
    InsereRecursivo(raiz, item);
}

void Arvore::InsereRecursivo(No *&p, char item)
{
    if (p == NULL)
    {
        p = new No;
        p->item = item;
    }
    else
    {
        if (item < p->item)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void Arvore::Caminha(int tipo)
{
    switch (tipo)
    {
    case 1:
        PreOrdem(raiz);
        break;
    case 2:
        InOrdem(raiz);
        break;
    case 3:
        PosOrdem(raiz);
        break;
    default:
        throw InvalidPathException();
    }
}

void Arvore::PreOrdem(No *p)
{
    if (p != NULL)
    {
        std::cout << p->item << " ";
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void Arvore::InOrdem(No *p)
{
    if (p != NULL)
    {
        InOrdem(p->esq);
        std::cout << p->item << " ";
        InOrdem(p->dir);
    }
}

void Arvore::PosOrdem(No *p)
{
    if (p != NULL)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        std::cout << p->item << " ";
    }
}
/*
void Arvore::PorNivel()
{
    Pilha p;
    No *aux;

    if (raiz != NULL)
    {
        p.Empilha(raiz);
        while (!p.Vazia())
        {
            aux = p.Desempilha();
            std::cout << aux->item << " ";
            if (aux->dir != NULL)
                p.Empilha(aux->dir);
            if (aux->esq != NULL)
                p.Empilha(aux->esq);
        }
    }
}
*/
void Arvore::Limpa()
{
    ApagaRecursivo(raiz);
}

void Arvore::ApagaRecursivo(No *p)
{
    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}