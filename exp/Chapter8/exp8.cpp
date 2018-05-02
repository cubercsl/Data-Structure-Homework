#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* ch[2];
    Node(int v = 0) { this->v = v, ch[0] = ch[1] = nullptr; }
    int v;
    int cmp(int x) { return x == v ? -1 : x > v; }
};

struct BinarySerchTree
{
    Node* root;
    BinarySerchTree() { root = nullptr; }
    ~BinarySerchTree() { destory(root); }
    void destory(Node* o)
    {
        if (o == nullptr) return;
        destory(o->ch[0]);
        destory(o->ch[1]);
        delete o;
    }
    void insert(int v, Node*& o)
    {
        if (o == nullptr)
        {
            o = new Node(v);
            return;
        }
        int d = o->cmp(v);
        assert(~d); // 保证插入之前不存在这个元素
        insert(v, o->ch[d]);
    }
    void print(int v, Node* o)
    {
        if (o == nullptr) return;
        print(v, o->ch[1]);
        if (o->cmp(v) == 1) return;
        cout << o->v << " ";
        print(v, o->ch[0]);
    }
    void insert(int v) { insert(v, root); }
    void print(int v) { print(v, root); }
};

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        BinarySerchTree T;
        for (auto& t : a) cin >> t;
        for (auto& t : a) T.insert(t);
        int v;
        cin >> v;
        T.print(v);
    }
}