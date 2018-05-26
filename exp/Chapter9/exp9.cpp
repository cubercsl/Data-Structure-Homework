#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
template <class ElemType>
int partition(vector<ElemType>& a, int low, int high)
{
    int key = a[low];

    while (low < high)
    {
        while (low < high && a[high] >= key) --high;
        a[low] = a[high];
        while (low < high && a[low] <= key) ++low;
        a[high] = a[low];
    }
    a[low] = key;
    return low;
}

template <class ElemType>
void quicksort(vector<ElemType>& a)
{
    int n = a.size();
    stack<PII> s;
    s.push({0, n - 1});
    while (!s.empty())
    {
        int low = s.top().first, high = s.top().second;
        s.pop();
        if (low >= high) continue;
        if (high - low > 2)
        {
            int mid = partition(a, low, high);
            if (high - mid > mid - low)
                s.push({mid + 1, high}), s.push({low, mid - 1});
            else
                s.push({low, mid - 1}), s.push({mid + 1, high});
        }
        if (high - low == 1)
            if (a[high] > a[low]) swap(a[high], a[low]);
        if (high - low == 2)
        {
            if (a[low] > a[low + 1]) swap(a[low], a[low + 1]);
            if (a[low] > a[high]) swap(a[low], a[high]);
            if (a[low + 1] > a[high]) swap(a[low + 1], a[high]);
        }
        for (auto& t : a) cout << t << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (auto& t : v) cin >> t;
        quicksort(v);
    }
}