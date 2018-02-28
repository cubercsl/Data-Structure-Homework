#include <bits/stdc++.h>
using namespace std;

void frequency(const string& s, map<char, int>& M)
{
    for (auto& ch : s) M[ch]++;
}

int main()
{
    string s;
    cin >> s;
    map<char, int> M;
    frequency(s, M);
    for (auto& t : M) cout << t.first << " " << t.second << endl;
}