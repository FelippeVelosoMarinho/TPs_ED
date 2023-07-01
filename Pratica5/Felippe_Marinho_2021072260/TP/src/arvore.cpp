#include "../include/arvore.hpp"

Arvore::Arvore(/* args */)
{
}

Arvore::~Arvore()
{
}

void Arvore::dumpTree(TipoApontador *T, int level, prm_t *prm)
{
    if ((*T) != NULL)
    {
        for (int i = 0; i < level; i++)
            fprintf(prm->saida, "    ");
        fprintf(prm->saida, " %3ld (%d)\n", (*T)->Reg.Chave, level);
        dumpTree(&(*T)->Esq, level + 1, prm);
        dumpTree(&(*T)->Dir, level + 1, prm);
    }
}

int Arvore::createTree(TipoNo **curr, int level, prm_t *prm)
{
    // create node
    (*curr) = (TipoNo *)malloc(sizeof(TipoNo));
    (*curr)->Esq = (*curr)->Dir = NULL;
    // set type
    if (drand48() > ((8.0 * (1 << level) * prm->treesize)) / (((1 << prm->numlevel) * prm->numno)))
    {
        (*curr)->Reg.Chave = prm->treesize;
        prm->treesize++;
        if (prm->treesize < prm->numno)
            createTree(&((*curr)->Esq), level + 1, prm);
        if (prm->treesize < prm->numno)
            createTree(&((*curr)->Dir), level + 1, prm);
    }
    else
    {
        (*curr)->Reg.Chave = prm->treesize;
        prm->treesize++;
    }
    return prm->treesize;
}

// função auxiliar que cria uma árvore de 10 nós
TipoNo* Arvore::criaArvoreDezNos(prm_t *prm)
{
    TipoNo *nos[10];
    for (int i = 0; i < 10; i++)
    {
        nos[i] = (TipoNo *)malloc(sizeof(TipoNo));
        // nos[i]->valor = i;
        nos[i]->Esq = nos[i]->Dir = NULL;
    }

    nos[0]->Esq = nos[1];
    nos[0]->Dir = nos[2];
    nos[1]->Esq = nos[3];
    nos[1]->Dir = nos[4];
    nos[2]->Esq = nos[5];
    nos[2]->Dir = nos[6];
    nos[4]->Esq = nos[7];
    nos[4]->Dir = nos[8];
    nos[5]->Esq = nos[9];

    prm->treesize = 10;
    return nos[0];
}

// função para percorrer a árvore em pré-ordem
void Arvore::preOrder(TipoNo *node, int *order, int *count)
{
    if (node == NULL)
        return;

    // adiciona a chave do nó atual no vetor e incrementa o contador
    order[*count] = node->Reg.Chave;
    (*count)++;

    // chama recursivamente a função para o filho esquerdo e depois para o filho direito
    preOrder(node->Esq, order, count);
    preOrder(node->Dir, order, count);
}

// função para percorrer a árvore em in-ordem
void Arvore::inOrder(TipoNo *node, int *order, int *count)
{
    if (node == NULL)
        return;

    // chama recursivamente a função para o filho esquerdo
    inOrder(node->Esq, order, count);

    // adiciona a chave do nó atual no vetor e incrementa o contador
    order[*count] = node->Reg.Chave;
    (*count)++;

    // chama recursivamente a função para o filho direito
    inOrder(node->Dir, order, count);
}

// função para percorrer a árvore em pós-ordem
void Arvore::postOrder(TipoNo *node, int *order, int *count)
{
    if (node == NULL)
        return;

    // chama recursivamente a função para o filho esquerdo e depois para o filho direito
    postOrder(node->Esq, order, count);
    postOrder(node->Dir, order, count);

    // adiciona a chave do nó atual no vetor e incrementa o contador
    order[*count] = node->Reg.Chave;
    (*count)++;
}

int Arvore::ancestral(int i, int j, TipoNo *raiz)
{
    int path_i[raiz->Reg.Chave], path_j[raiz->Reg.Chave];
    int count_i = 0, count_j = 0;

    // encontra caminho de i
    preOrder(raiz, path_i, &count_i);
    int idx_i;
    for (idx_i = 0; idx_i < count_i; idx_i++)
    {
        if (path_i[idx_i] == i)
        {
            break;
        }
    }

    // encontra caminho de j
    inOrder(raiz, path_j, &count_j);
    int idx_j;
    for (idx_j = 0; idx_j < count_j; idx_j++)
    {
        if (path_j[idx_j] == j)
        {
            break;
        }
    }

    // percorre os vetores até encontrar o primeiro elemento diferente
    int idx_anc;
    for (idx_anc = 0; idx_anc < count_i && idx_anc < count_j; idx_anc++)
    {
        if (path_i[idx_anc] != path_j[idx_anc])
        {
            break;
        }
    }

    return path_i[idx_anc - 1];
}