#include "../include/arvore.hpp"

Arvore::Arvore()
{

}

Arvore::~Arvore()
{
   
}

void Arvore::insert(int value)
{
    Node *node = new Node(value);
    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        Node *current = root;
        Node *parent = nullptr;
        while (true)
        {
            parent = current;
            if (value < current->value)
            {
                current = current->left;
                if (current == nullptr)
                {
                    parent->left = node;
                    break;
                }
            }
            else
            {
                current = current->right;
                if (current == nullptr)
                {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

void Arvore::printPreorderHelper(Node *node, int *path, int &index) const
{
    if (node != nullptr)
    {
        path[index++] = node->value;
        printPreorderHelper(node->left, path, index);
        printPreorderHelper(node->right, path, index);
    }
}

void Arvore::printPreorder(int *path) const
{
    int index = 0;
    printPreorderHelper(root, path, index);
}

void Arvore::printInorderHelper(Node *node, int *path, int &index) const
{
    if (node != nullptr)
    {
        printInorderHelper(node->left, path, index);
        path[index++] = node->value;
        printInorderHelper(node->right, path, index);
    }
}

void Arvore::printInorder(int *path) const
{
    int index = 0;
    printInorderHelper(root, path, index);
}

void Arvore::printPostorderHelper(Node *node, int *path, int &index) const
{
    if (node != nullptr)
    {
        printPostorderHelper(node->left, path, index);
        printPostorderHelper(node->right, path, index);
        path[index++] = node->value;
    }
}

void Arvore::printPostorder(int *path) const
{
    int index = 0;
    printPostorderHelper(root, path, index);
}

bool Arvore::isAncestorHelper(Node *node, int i, int j) const
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->value == i || node->value == j)
    {
        return true;
    }
    bool left = isAncestorHelper(node->left, i, j);
    bool right = isAncestorHelper(node->right, i, j);
    if (left && right)
    {
        return true;
    }
    return false;
}

bool Arvore::isAncestor(int i, int j) const
{
    return isAncestorHelper(root, i, j);
}