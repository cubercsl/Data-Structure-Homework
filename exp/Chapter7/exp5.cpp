#define __DEBUG__
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge
{
    int from, to, cost;
    Edge() {}
    Edge(int u, int v, int c) : from(u), to(v), cost(c) {}
};

const int N = 1 << 17;
struct BellmanFord
{
    int n;
    vector<Edge> edges;
    vector<int> G[N];
    int d[N], tmp[N], p[N];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) vector<int>().swap(G[i]);
    }
    void addedge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
        G[u].push_back(edges.size() - 1);
    }
    void bellmanford(int s)
    {
        memset(d, 0x3f, sizeof(d));
        memset(p, -1, sizeof(p));
        d[s] = 0;
        for (int k = 1; k < n; k++)
        {
            memcpy(tmp, d, sizeof(d));
            for (auto& e : edges)
            {
                int &u = e.from, &v = e.to, &w = e.cost;
                if (tmp[v] > d[u] + w)
                    tmp[v] = d[u] + w, p[v] = u;
            }
            memcpy(d, tmp, sizeof(d));
#ifdef __DEBUG__
            printf("第%d次迭代:\n", k);
            for (int i = 0; i < n; i++) printf("%2d%c", d[i], " \n"[i == n - 1]);
            for (int i = 0; i < n; i++) printf("%2d%c", p[i], " \n"[i == n - 1]);
#endif
        }
    }
} gao;

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        gao.init(n);
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            gao.addedge(u, v, w);
        }
        gao.bellmanford(0);
    }
    return 0;
}