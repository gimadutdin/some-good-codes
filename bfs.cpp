#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > g;
char used[10005];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    used[x] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int i = 0; i < (int)g[t].size(); i++)
        {
            if (!used[g[t][i]])
            {
                q.push(g[t][i]);
                used[g[t][i]] = 1;
            }
        }
    }
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
    bfs(s);
    return 0;
}
