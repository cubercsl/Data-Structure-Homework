#include <iostream>
using namespace std;

struct Node
{
    Node* ch[2];
    int data, count;
    Node(int v = 0) { data = v, count = 0, ch[0] = ch[1] = nullptr; }
    int cmp(int x) { return x == data ? -1 : x > data; }
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
    bool insert(int v)
    {
        Node *o = root, *fa = nullptr;
        while (o != nullptr)
        {
            fa = o;
            int d = o->cmp(v);
            if (!~d)
            {
                o->count++;
                cerr << "count = " << o->count << endl;
                return true;
            }
            o = o->ch[d];
        }
        o = new Node(v);
        if (fa == nullptr)
        {
            root = o;
            return false;
        }
        int d = fa->cmp(v);
        fa->ch[d] = o;
        return false;
    }
};

int main()
{
    BinarySerchTree t;
    int n;
    while (cin >> n)
        if (!t.insert(n)) cout << "Success" << endl;
}