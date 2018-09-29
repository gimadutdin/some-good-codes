#include "Node.h"

Node::Node(int value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

int Node::getValue()
{
    return this->value;
}

void Node::setLeft(Node *left)
{
    this->left = left;
}

Node *Node::getLeft()
{
    return this->left;
}

void Node::setRight(Node *right)
{
    this->right = right;
}

Node *Node::getRight()
{
    return this->right;
}
