#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (v[i] > v[j])
                    c[i]++;
                else
                    c[j]++;
        int p = 0;
        while (p < n)
            if (c[p] < p)
                swap(v[p], v[c[p]]), swap(c[p], c[c[p]]);
            else
                p++;
        for (auto& t : v) cout << t << " ";
        cout << endl;
    }
    return 0;
}