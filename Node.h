#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
    private:
    int value;
    Node *left, *right;

    public:
    Node(int value);
    int getValue();

    void setLeft(Node *left);
    Node *getLeft();

    void setRight(Node *right);
    Node *getRight();

};

#endif // NODE_H_INCLUDED
