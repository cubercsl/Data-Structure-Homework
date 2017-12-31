#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    while (cin >> n)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0)
                    a = 1;
                else
                {
                    if (j == i)
                        b = 1;
                    else
                        b = q.front(), q.pop();
                    q.push(a + b);
                    swap(a, b);
                }
                cout << a << " ";
            }
            cout << endl;
        }
    }
}