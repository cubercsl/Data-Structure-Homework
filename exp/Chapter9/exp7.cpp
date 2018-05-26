#include <bits/stdc++.h>
using namespace std;
template <class ElemType>
struct Node
{
    ElemType data;
    int next, prior;
};

template <class ElemType>
void debug(Node<ElemType> elem[])
{
    for (int p = elem[0].next; p; p = elem[p].next) cout << elem[p].data << " ";
    cout << endl;
}

template <class ElemType>
void DblLinkQuickSort(Node<ElemType> elem[], int left, int right)
{
    int p = elem[left].next, q = elem[right].prior;
    if (p == right || p == q) return;
    while (p != q)
    {
        if (elem[q].data < elem[p].data)
        {
            int r = elem[q].prior;
            elem[r].next = elem[q].next, elem[elem[q].next].prior = r;
            elem[q].prior = elem[p].prior, elem[q].next = p;
            elem[elem[p].prior].next = q, elem[p].prior = q;
            q = r;
        }
        else
            q = elem[q].prior;
    }
    debug(elem);
    DblLinkQuickSort(elem, left, p);
    DblLinkQuickSort(elem, p, right);
}

int main()
{
    int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
    int n = 10;
    Node<int>* table; // 静态链表

    table = new Node<int>[n + 1];
    for (int p = 1; p <= n; p++)
    { // 根据数组a中的元素构造静态链表
        table[p].data = a[p - 1];
        table[p - 1].next = p;
        table[p].prior = p - 1;
    }
    table[0].prior = n;
    table[n].next = 0;
    DblLinkQuickSort(table, 0, 0);
    cin >> n;
    delete[] table;
}