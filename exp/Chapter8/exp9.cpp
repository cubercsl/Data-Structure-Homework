#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, height, size;
    Node* ch[2];
    Node(int value = 0) : key(value) { ch[0] = ch[1] = nullptr, height = size = 1; }
    void maintain()
    {
        height = 1, size = 1;
        if (ch[0] != nullptr) height = max(ch[0]->height + 1, height), size += ch[0]->size;
        if (ch[1] != nullptr) height = max(ch[1]->height + 1, height), size += ch[1]->size;
    }
    int cmp(int x) { return x == key ? -1 : x > key; }
};

class AVLTree
{
public:
    AVLTree();  // 构造函数
    ~AVLTree(); // 析构函数

    void insert(int key); // 插入指定元素
    int kth(int k);       // 查找第k个元素
#ifdef __DEBUG__
    void debug(); // debug
#endif

private:
    Node* root;                     // 根节点
    int height(Node* o) const;      // 树的高度
    void rotate(Node*& o, bool d);  // 旋转(0为左旋)
    void insert(Node*& o, int key); // 插入指定元素
    void destory(Node* o);          // 销毁平衡二叉树
    Node* kth(Node* o, int k);      // 查找第k个元素
#ifdef __DEBUG__
    void dfs(Node* o); // debug
#endif
};

AVLTree::AVLTree() { root = nullptr; }

AVLTree::~AVLTree() { destory(root); }

void AVLTree::destory(Node* o)
{
    if (o == nullptr) return;
    destory(o->ch[0]);
    destory(o->ch[1]);
}

int AVLTree::height(Node* o) const { return o == nullptr ? 0 : o->height; }

void AVLTree::insert(int key) { insert(root, key); }

void AVLTree::insert(Node*& o, int key)
{
    if (o == nullptr)
    {
        o = new Node(key);
        return;
    }
    int d = o->cmp(key);
    if (!~d) return; // 存在相同的元素
    insert(o->ch[d], key);
    if (height(o->ch[d]) - height(o->ch[d ^ 1]) == 2) // 失衡
    {
        if (d != o->ch[d]->cmp(key)) rotate(o->ch[d], d); // LR或者RL
        rotate(o, d ^ 1);                                 // LL或者RR
    }
    o->maintain();
}

void AVLTree::rotate(Node*& o, bool d)
{
    Node* k = o->ch[d ^ 1];
    o->ch[d ^ 1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

int AVLTree::kth(int k)
{
    Node* o = kth(root, k);
    assert(o != nullptr);
    return o->key;
}

Node* AVLTree::kth(Node* o, int k)
{
    if (o == nullptr) return nullptr;
    int lsize = o->ch[0] == nullptr ? 1 : o->ch[0]->size + 1;
    if (lsize == k) return o;
    return lsize > k ? kth(o->ch[0], k) : kth(o->ch[1], k - lsize);
}

#ifdef __DEBUG__
void AVLTree::debug()
{
    dfs(root);
}

void AVLTree::dfs(Node* o)
{
    if (o == nullptr) return;
    dfs(o->ch[0]);
    cout << "address: " << o << " key: " << o->key << " lch: " << o->ch[0] << " rch: " << o->ch[1] << endl;
    dfs(o->ch[1]);
}
#endif

int main()
{
    AVLTree t;
    int op, x;
    while (cin >> op >> x)
    {
        if (op == 0) // 插入
            t.insert(x);
        else if (op == 1) // 查询
        {
            int v = t.kth(x);
            assert(x - 1 == v);
            cout << x << " " << v << endl;
        }
#ifdef __DEBUG__
        t.debug();
#endif
    }
}