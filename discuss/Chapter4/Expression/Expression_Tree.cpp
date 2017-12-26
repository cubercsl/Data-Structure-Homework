#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

class Expression_Tree
{
    int lch[N], rch[N]; // 左子树和右子树的编号
    char op[N];         // 结点的运算符或操作数
    int nc;             // 结点总数

public:
    Expression_Tree() : nc(0)
    {
        memset(lch, 0, sizeof(lch));
        memset(rch, 0, sizeof(rch));
    }
    int build(char* s, int x, int y)
    {
        int c1 = -1, c2 = -1, p = 0;
        int u;
        if (y - x == 1) {
            u = ++nc;
            lch[u] = rch[u] = 0;
            op[u] = s[x];
            return u;
        }
        for (int i = x; i < y; i++) {
            switch (s[i])
            {
            case '(': p++; break;
            case ')': p--; break;
            case '+':
            case '-':
                if (!p) c1 = i;
                break;
            case '*':
            case '/':
                if (!p) c2 = i;
                break;
            }
        }
        if (c1 < 0) c1 = c2;                       // 找不到括号外面的加减号
        if (c1 < 0) return build(s, x + 1, y - 1); // 表达式最外层是括号
        u = ++nc;
        lch[u] = build(s, x, c1);
        rch[u] = build(s, c1 + 1, y);
        op[u] = s[c1];
        return u;
    }
    void preorder(int u = 1)
    {
        if (!u) return;
        cout << op[u] << ' ';
        preorder(lch[u]);
        preorder(rch[u]);
    }
    void inorder(int u = 1)
    {
        if (!u) return;
        inorder(lch[u]);
        cout << op[u] << ' ';
        inorder(rch[u]);
    }
    void postorder(int u = 1)
    {
        if (!u) return;
        postorder(lch[u]);
        postorder(rch[u]);
        cout << op[u] << ' ';
    }
};

int main()
{
    char s[N];
    while (cin >> s)
    {
        // a+b*(c-d)-e/f
        Expression_Tree tree;
        int n = strlen(s);
        tree.build(s, 0, n);
        cout << "PreOrder: ";
        tree.preorder();
        cout << endl;
        cout << "InOrder: ";
        tree.inorder();
        cout << endl;
        cout << "PostOrder: ";
        tree.postorder();
        cout << endl;
    }
}
