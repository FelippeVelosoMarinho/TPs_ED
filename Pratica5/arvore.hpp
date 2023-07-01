#ifndef ARVORE_HPP
#define ARVORE_HPP

class Arvore
{
private:
    struct Node
    {
        int value;
        Node *left;
        Node *right;
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

    void printPreorderHelper(Node *node, int *path, int &index) const;
    void printInorderHelper(Node *node, int *path, int &index) const;
    void printPostorderHelper(Node *node, int *path, int &index) const;
    bool isAncestorHelper(Node *node, int i, int j) const;

public:
    Arvore();
    ~Arvore();
    void insert(int value);
    void printPreorder(int *path) const;
    void printInorder(int *path) const;
    void printPostorder(int *path) const;
    bool isAncestor(int i, int j) const;
};

#endif