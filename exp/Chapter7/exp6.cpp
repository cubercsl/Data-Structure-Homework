#define __DEBUG__
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 105;
struct Floyd
{
    int n;
    int d[N][N], p[N][N];
    void init(int n)
    {
        this->n = n;
        memset(d, 0x3f, sizeof(d));
        memset(p, -1, sizeof(p));
        for (int i = 0; i < n; i++) d[i][i] = 0;
    }
    void addedge(int u, int v, int w) { d[u][v] = min(d[u][v], w); }
    void floyd()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] != INF) p[i][j] = i;
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j], p[i][j] = p[k][j];
#ifdef __DEBUG__
            puts("####################");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    printf("%3d%c", d[i][j] != INF ? d[i][j] : -1, " \n"[j == n - 1]);
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
            gao.addedge(v, u, w);
        }
        gao.floyd();
    }
    return 0;
}