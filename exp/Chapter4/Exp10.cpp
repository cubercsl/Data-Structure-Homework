#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int main()
{
    int m, n, ans;
    while (cin >> m >> n)
    {
        stack<PII> s;
        s.push(make_pair(m, n));
        while (!s.empty())
        {
            PII tmp = s.top();
            int M = tmp.first, N = tmp.second;
            cout << M << " " << N << endl;
            if (M && N)
                s.push(make_pair(M, N - 1));
            else if (N == 0)
            {
                s.pop();
                s.push(make_pair(M - 1, 1));
            }
            else if (M == 0)
            {
                s.pop();
                if (!s.empty())
                    s.top().first--, s.top().second = N + 1;
                else
                    ans = N + 1;
            }
        }
        cout << ans << endl;
    }
}