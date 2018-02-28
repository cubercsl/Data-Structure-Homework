#include <bits/stdc++.h>
using namespace std;

const int N = 100;
void solve(int a[][N], const int& n, const int& m)
{
    for (int i = 0; i < n; i++)
    {
        int maxv = INT_MIN;
        for (int j = 0; j < m; j++) maxv = max(maxv, a[i][j]);
        for (int j = 0; j < m; j++)
            if (a[i][j] == maxv)
            {
                int minv = INT_MAX;
                for (int k = 0; k < n; k++) minv = min(minv, a[k][j]);
                if (maxv == minv) cout << i << " " << j << endl;
            }
    }
}

int main()
{
    int a[N][N];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    solve(a, n, m);
    return 0;
}