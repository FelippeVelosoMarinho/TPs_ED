#include "../include/tree.hpp"

node *insertAVL(node *T, int x, stat_t *st)
{
    if (T == NULL)
    {
        T = (node *)malloc(sizeof(node));
        T->data = x;
        T->left = NULL;
        T->right = NULL;
    }
    else if (x > T->data) // insert in right subtree
    {
        T->right = insertAVL(T->right, x, st);
        if (BF(T) == -2)
        {
            if (x > T->right->data)
            {
                T = RR(T);
                st->RR++;
            }
            else
            {
                T = RL(T);
                st->RL++;
            }
        }
    }
    else if (x < T->data)
    {
        T->left = insertAVL(T->left, x, st);
        if (BF(T) == 2)
        {
            if (x < T->left->data)
            {
                T = LL(T);
                st->LL++;
            }
            else
            {
                T = LR(T);
                st->LR++;
            }
        }
    }
    T->ht = height(T);

    return (T);
}

node *insertGalo(node *T, int x, stat_t *st)
{
    if (T == NULL)
    {
        T = (node *)malloc(sizeof(node));
        T->data = x;
        T->left = NULL;
        T->right = NULL;
    }
    else if (x > T->data) // insert in right subtree
    {
        T->right = insertGalo(T->right, x, st);
        if (BF(T) == -2)
        {
            if (x > T->right->data)
            {
                T = RR(T);
                st->RR++;
            }
            else
            {
                T = RL(T);
                st->RL++;
            }
        }
    }
    else if (x < T->data)
    {
        T->left = insertGalo(T->left, x, st);
        if (BF(T) == 2)
        {
            if (x < T->left->data)
            {
                T = LL(T);
                st->LL++;
            }
            else
            {
                T = LR(T);
                st->LR++;
            }
        }
    }
    T->ht = height(T);

    // Balanceamento alvi-negro
    return fixInsertion(T, T->left); // ou T = fixInsertion(T, T->right);
}

bool isWhite(node *n)
{
    if (n == NULL)
        return false;
    return n->color == WHITE;
}

node *fixInsertion(node *T, node *newNode)
{
    if (newNode == T)
    {
        newNode->color = BLACK;
        return NULL;
    }

    node *parent = NULL;
    node *grandparent = NULL;
    node *uncle = NULL;
    node *current = newNode;

    while (current != T && isWhite(current) && isWhite(current->left) && isWhite(current->right))
    {
        parent = current->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            uncle = grandparent->right;

            // Caso 1: O tio é vermelho
            if (isWhite(uncle))
            {
                grandparent->color = WHITE;
                parent->color = BLACK;
                uncle->color = BLACK;
                current = grandparent;
            }
            else
            {
                // Caso 2: O tio é preto e o nó é um filho direito
                if (current == parent->right)
                {
                    current = parent;
                    T = rotateleft(current);
                }

                // Caso 3: O tio é preto e o nó é um filho esquerdo
                parent = current->parent;
                grandparent = parent->parent;
                parent->color = BLACK;
                grandparent->color = WHITE;
                T = rotateright(grandparent);
            }
        }
        else
        {
            // Mesmas operações, mas com os lados invertidos
        }
    }

    T->color = BLACK;
    return T;
}

node *Delete(node *T, int x, stat_t *st)
{
    node *p;
    if (T == NULL)
    {
        return NULL;
    }
    else if (x > T->data) // insert in right subtree
    {
        T->right = Delete(T->right, x, st);
        if (BF(T) == 2)
        {
            if (BF(T->left) >= 0)
            {
                T = LL(T);
                st->LL++;
            }
            else
            {
                T = LR(T);
                st->LR++;
            }
        }
    }
    else if (x < T->data)
    {
        T->left = Delete(T->left, x, st);
        if (BF(T) == -2)
        { // Rebalance during windup
            if (BF(T->right) <= 0)
            {
                T = RR(T);
                st->RR++;
            }
            else
            {
                T = RL(T);
                st->RL++;
            }
        }
    }
    else
    {
        // data to be deleted is found
        if (T->right != NULL)
        { // delete its inorder succesor
            p = T->right;
            while (p->left != NULL)
                p = p->left;
            T->data = p->data;
            T->right = Delete(T->right, p->data, st);
            if (BF(T) == 2)
            { // Rebalance during windup
                if (BF(T->left) >= 0)
                {
                    T = LL(T);
                    st->LL++;
                }
                else
                {
                    T = LR(T);
                    st->LR++;
                }
            }
        }
        else
            return (T->left);
    }
    T->ht = height(T);
    return (T);
}

int height(node *T)
{
    int lh, rh;
    if (T == NULL)
        return (0);
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}

node *rotateright(node *x)
{
    node *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

node *rotateleft(node *x)
{
    node *y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

node *RR(node *T)
{
    T = rotateleft(T);
    return (T);
}

node *LL(node *T)
{
    T = rotateright(T);
    return (T);
}

node *LR(node *T)
{
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return (T);
}

node *RL(node *T)
{
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return (T);
}

int BF(node *T)
{
    int lh, rh;
    if (T == NULL)
        return (0);

    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;

    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;

    return (lh - rh);
}

void preorder(node *T)
{
    if (T != NULL)
    {
        printf("%d(Bf=%d)", T->data, BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(node *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d(Bf=%d)", T->data, BF(T));
        inorder(T->right);
    }
}

void dump(node *T, int level, char *pref)
{
    if (T != NULL)
    {
        printf("%s ", pref);
        for (int i = 0; i < level; i++)
            printf("    ");
        printf("%3d (Bf=%d, H=%d)\n", T->data, BF(T), T->ht);
        dump(T->left, level + 1, pref);
        dump(T->right, level + 1, pref);
    }
}
