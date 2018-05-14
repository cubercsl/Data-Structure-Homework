#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, height, bf;
    Node* ch[2];
    Node(int value = 0) : key(value) { ch[0] = ch[1] = nullptr, height = bf = 1; }
    void maintain()
    {
        height = 1, bf = 0;
        if (ch[0] != nullptr) height = max(ch[0]->height + 1, height), bf -= ch[0]->height;
        if (ch[1] != nullptr) height = max(ch[1]->height + 1, height), bf += ch[1]->height;
    }
    int cmp(int x) { return x == key ? -1 : x > key; }
};

class AVLTree
{
public:
    AVLTree();  // 构造函数
    ~AVLTree(); // 析构函数

    void insert(int key); // 插入指定元素
    int height() const;   // 树的高度
#ifdef __DEBUG__
    void debug(); // debug
#endif

private:
    Node* root;                     // 根节点
    int height(Node* o) const;      // 树的高度
    void rotate(Node*& o, bool d);  // 旋转(0为左旋)
    void insert(Node*& o, int key); // 插入指定元素
    void destory(Node* o);          // 销毁平衡二叉树
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

int AVLTree::height() const
{
    Node* o = root;
    int ret = 0;
    while (o != nullptr)
    {
        ret++;
        int d = o->bf == 1;
        o = o->ch[d];
    }
    return ret;
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
    while (cin >> op)
    {
        if (op == 0) // 插入
        {
            cin >> x;
            t.insert(x);
        }
        else
            cout << t.height() << endl;
#ifdef __DEBUG__
        t.debug();
#endif
    }
}