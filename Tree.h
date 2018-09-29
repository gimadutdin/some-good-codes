#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Node.h"

class BST
{
    private:
    Node *root;
    int nodeCount;

    public:
    Tree();

    void addNode(Node *node);
    Node *findNode(int value);

    void show(Node *v = root, level = 0);
};

#endif // TREE_H_INCLUDED
