#define __DEBUG__
#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from, to, cost;
    Edge() {}
    Edge(int u, int v, int w) : from(u), to(v), cost(w) {}
};
struct HeapNode
{
    int from, cost;
    HeapNode() {}
    HeapNode(int u, int d) : from(u), cost(d) {}
    bool operator<(const HeapNode& rhs) const
    {
        return cost > rhs.cost;
    }
};

const int N = 1 << 17;
struct Dijkstra
{
    int n;
    vector<Edge> edges;
    vector<int> G[N];
    bool done[N];
    int d[N], p[N];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) vector<int>().swap(G[i]);
        edges.clear();
    }
    void addedge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
        G[u].push_back(edges.size() - 1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> q;
        memset(d, 0x3f, sizeof(d));
        memset(p, -1, sizeof(p));
        memset(done, 0, sizeof(done));
        d[s] = 0;
        q.push({s, 0});
        while (!q.empty())
        {
            HeapNode t = q.top();
            q.pop();
            int& u = t.from;
            if (done[u]) continue;
            done[u] = true;
            for (auto& id : G[u])
            {
                Edge& e = edges[id];
                if (d[e.to] > d[e.from] + e.cost)
                {
                    d[e.to] = d[e.from] + e.cost;
                    p[e.to] = e.from;
                    q.push({e.to, d[e.to]});
                }
            }
#ifdef __DEBUG__
            puts("####################");
            for (int i = 0; i < n; i++) printf("%2d%c", done[i], " \n"[i == n - 1]);
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
        gao.dijkstra(0);
    }
}