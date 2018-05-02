#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1 << 17;
    cout << n << endl;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;
    cout << rand() % n << endl;
    return 0;
}