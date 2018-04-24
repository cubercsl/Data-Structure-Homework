#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10;
int G[N][N];

int lowc[N];
bool vis[N];
int Prim(int cost[][N], int n)
{
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (int i = 1; i < n; i++) lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF, p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && minc > lowc[j]) minc = lowc[j], p = j;
        if (minc == INF) return -1;
        vis[p] = 1;
        ans += minc;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > cost[p][j]) lowc[j] = cost[p][j];
    }
    return ans;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        memset(G, 0x3f, sizeof(G));
        while(m--)
        {
            static int u, v, w;
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }
        cout << Prim(G, n) << endl;
    }
    return 0;
}