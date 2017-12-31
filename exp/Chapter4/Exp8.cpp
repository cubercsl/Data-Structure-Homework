#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0, x;
    stack<int> s;
    while (cin >> x, x)
        s.push(x);
    cout << sum << endl;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
        cout << sum << endl;
    }
}