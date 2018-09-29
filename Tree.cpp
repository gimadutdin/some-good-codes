#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
    this->nodeCount = 0;
}

void Tree::show(Node *v = root, level = 0)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
    cout << v->getValue() << "\n";
    Tree::show(v->getLeft(), level + 1);
    Tree::show(v->getRight(), level + 1);
}
