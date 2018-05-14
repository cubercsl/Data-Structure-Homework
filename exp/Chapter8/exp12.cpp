#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* ch[2];
    Node(int v = 0) { this->v = v, ch[0] = ch[1] = nullptr; }
    int v;
    int cmp(int x) { return x > v; }
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
    void insert(int v) { insert(v, root); }
    void print()
    {
        int cur = -1, cnt = 0;
        dfs(root, cur, cnt);
        cout << endl;
        cout << "cnt = " << cnt << endl;
    }
    void dfs(Node* o, int& cur, int& cnt)
    {
        if (o == nullptr) return;
        dfs(o->ch[0], cur, cnt);
        if (o->v == cur)
            cnt++;
        else
            cout << o->v << endl;
        dfs(o->ch[1], cur, cnt);
    }
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
        T.print();
    }
}
