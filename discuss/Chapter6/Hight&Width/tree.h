#ifndef __TREE_H__
#define __TREE_H__
#include <algorithm>
#include <queue>

const int MAXSIZE = 100;
struct Tree
{
    int sz, root;
    int ch[MAXSIZE][2];                      // 左儿子右兄弟
    int newnode(int lch = -1, int rch = -1); // 新建结点
    Tree();                                  // 构造函数

    int width();
    int depth();
    int dfs(int u);

    void test(); // 测试
};

Tree::Tree()
{
    sz = 0;
    root = -1;
}

int Tree::newnode(int lch, int rch)
{
    ch[sz][0] = lch;
    ch[sz][1] = rch;
    return sz++;
}

int Tree::width()
{
    if (root == -1) return 0;
    std::queue<int> q;
    q.push(root);
    int n = 1, ret = 1;
    while (!q.empty())
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int p = q.front();
            q.pop();
            for (p = ch[p][0]; ~p; p = ch[p][1]) ++count, q.push(p);
        }
        ret = std::max(n = count, ret);
    }
    return ret;
}

int Tree::depth() { return dfs(root); }

int Tree::dfs(int u)
{
    if (u == -1) return 0;
    int ret = 0;
    for (u = ch[u][0]; ~u; u = ch[u][1]) ret = std::max(ret, dfs(u));
    return ret + 1;
}

void Tree::test()
{
    root = newnode(1); // 0
    newnode(4, 2);     // 1
    newnode(6, 3);     // 2
    newnode(7);        // 3
    newnode(-1, 5);    // 4
    newnode(10);       // 5
    newnode();         // 6
    newnode(-1, 8);    // 7
    newnode(12, 9);    // 8
    newnode();         // 9
    newnode(-1, 11);   // 10
    newnode();         // 11
    newnode(-1, 13);   // 12
    newnode();         // 13
}

#endif