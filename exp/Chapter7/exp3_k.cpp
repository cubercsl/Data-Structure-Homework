#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<int, PII> Edge;
vector<Edge> G;
const int N = 10;
int fa[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same(int x, int y) { return find(x) == find(y); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) fa[y] = x;
}

void add_edge(int u, int v, int d) { G.push_back(make_pair(d, make_pair(u, v))); }
int Kruskal(int n)
{
    iota(fa, fa + n, 0); // 并查集初始化
    sort(G.begin(), G.end());
    int num = 0, ret = 0;
    for (auto& e : G)
    {
        int x = e.Y.X, y = e.Y.Y;
        int d = e.X;
        if (!same(x, y))
        {
            unite(x, y);
            num++;
            ret += d;
        }
        if (num == n - 1) break;
    }
    return ret;
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        G.clear();
        while (m--)
        {
            static int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        cout << Kruskal(n) << endl;
    }
    return 0;
}