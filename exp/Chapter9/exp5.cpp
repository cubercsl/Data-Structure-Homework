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
    for (int p = elem[0].next; ~p; p = elem[p].next) cout << elem[p].data << " ";
    cout << endl;
}

template <class ElemType>
void DblLinkBubbleSort(Node<ElemType> elem[])
{
    bool finish = false;
    int r = -1;
    for (int p = elem[0].next; p != r && !finish; p = elem[0].next)
    {
        finish = true;
        for (int q = elem[p].next; q != r; q = elem[p].next)
        {
            if (elem[p].data > elem[q].data)
            { // swap
                elem[elem[p].prior].next = q;
                if (~elem[q].next) elem[elem[q].next].prior = p;
                elem[p].next = elem[q].next, elem[q].prior = elem[p].prior;
                elem[q].next = p, elem[p].prior = q;
                finish = false;
            }
            else
                p = q;
        }
        debug(elem);
        r = p;
    }
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
    table[0].prior = -1;
    table[n].next = -1;
    DblLinkBubbleSort(table);
    delete []table;
}