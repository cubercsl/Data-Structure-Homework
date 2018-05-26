#include <bits/stdc++.h>
using namespace std;
template <class ElemType>
void BubbleSort(vector<ElemType>& a)
{
    int n = a.size();
    bool finish = false;
    for (int i = 0; i < n / 2 && !finish; i++)
    {
        finish = true;
        for (int j = i; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]), finish = false;
        for (int j = n - i - 1; j > i; j--)
            if (a[j - 1] > a[j]) swap(a[j - 1], a[j]), finish = false;
        for (auto& t : a) cout << t << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> a = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
    BubbleSort(a);
    int n;
    cin >> n;
    return 0;
}