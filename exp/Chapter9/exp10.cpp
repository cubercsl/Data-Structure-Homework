#include <bits/stdc++.h>
using namespace std;

template <class ElemType>
void BinaryInsertSort(ElemType a[], int n)
{
    ElemType* d = new ElemType[n];
    d[0] = a[0];
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > d[0])
        {
            int j = r;
            while (j && a[i] < d[j]) d[j + 1] = d[j], j--;
            d[j + 1] = a[i];
            r++;
        }
        else
        {
            if (l == 0)
                d[n - 1] = a[i], l = n - 1;
            else
            {
                int j = l;
                while (j < n && a[i] > d[j]) d[j - 1] = d[j], j++;
                d[j - 1] = a[i];
                l--;
            }
        }
    }
    for (int i = 0, j = l; i < n; i++, (++j) %= n) a[i] = d[j];
}

int main()
{
    int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
    int n = 10;
    BinaryInsertSort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
