#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > g;
char used[10005];

void dfs(int x)
{
    used[x] = 1;
    cout << x << " ";
    for (int i = 0; i < (int)g[x].size(); i++)
        if (!used[g[x][i]])
            dfs(g[x][i]);
}

int main()
{
    int n, m, s = -1;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (s == -1) s = x;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s);
    return 0;
}
