#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

int main()
{
    Tree *t = new Tree();
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k , v;
        cin >> k >> v;
        t->addNode(k, v);
    }
    t->show();

    return 0;
}
