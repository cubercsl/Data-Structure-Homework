#include <bits/stdc++.h>
using namespace std;

struct HeapNode
{
    int u, v, w;
    bool operator<(const HeapNode& rhs) const
    {
        return w < rhs.w;
    }
};

const int N = 10;
bool G[N][N];
bool vis[N];

void dfs(int u, int n)
{
    vis[u] = 1;
    for (int v = 0; v < n; v++)
        if (G[u][v] && !vis[v]) dfs(v, n);
}

bool judge(int n)
{
    memset(vis, 0, sizeof(vis));
    dfs(0, n);
    for (int i = 0; i < n; i++)
        if (!vis[i]) return false;
    return true;
}

int main()
{
    priority_queue<HeapNode> q;
    int n, m;
    while (cin >> n >> m)
    {
        int weight = 0;
        for (int i = 0; i < m; i++)
        {
            static int u, v, w;
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = 1;
            q.push((HeapNode){u, v, w});
            weight += w;
        }
        while (m > n - 1)
        {
            HeapNode e = q.top();
            q.pop();
            int u = e.u, v = e.v, w = e.w;
            G[u][v] = G[v][u] = 0;
            if (judge(n))
                m--, weight -= w, cout << u << " " << v << " " << w << endl;
            else
                G[u][v] = G[v][u] = 1;
        }
        cout << weight << endl;
    }
    return 0;
}