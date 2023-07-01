#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>
#include <iostream>

using namespace std;

enum Color
{
    WHITE,
    BLACK
};

typedef struct stat
{
    int RR;
    int LL;
    int RL;
    int LR;
} stat_t;

typedef struct node
{
    int data;
    struct node *left, *right, *parent;
    int ht;
    Color color; // Adicionar o campo color
} node;

bool isWhite(node* n);
bool isBlack(node* n);
node *insertAVL(node *, int, stat_t *);
node *insertGalo(node *, int, stat_t *);
node *Delete(node *, int, stat_t *);
void preorder(node *);
void inorder(node *);
void dump(node *, int, char *);
int height(node *);
bool isWhite(node *);
node* fixInsertion(node* T, node* newNode);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);