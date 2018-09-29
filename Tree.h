#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Node.h"

class Tree
{//binary search tree
    private:
    Node *root;
    int nodeCount;

    void addNode(Node *v, int key, int value);
    void show(Node *v, int level = 0);


    public:
    Tree();

    void addNode(int key, int value);
    Node *findNode(int key);

    void show();
};

#endif // TREE_H_INCLUDED
