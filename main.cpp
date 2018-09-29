#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

int main()
{
    Tree *bst = new Tree();
    int n, key, value;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> key >> value;
        bst->addNode(key, value);
    }
    bst->show();

    cout << endl << "Enter key of element to search: ";
    cin >> key;
    Node *f = bst->findNode(key);
    if (f != nullptr)
    {
        cout << "Element found: " << "(" << f->getKey() << ", " << f->getValue() << ")\n";
    } else
    {
        cout << "Element not found!";
    }

    return 0;
}
