#ifndef __TREE_H__
#define __TREE_H__

#include "TreeNode.h"
#include <queue>
template <class ElemType>
class Tree
{
protected:
    TreeNode<ElemType>* root;
    Destroy(TreeNode<ElemType>*& r);

public:
    Tree();
    Tree(const ElemType& e);
    virtual ~Tree();
    void InsertChild(TreeNode<ElemType>* p, const ElemType& e);
    void InsertSibling(TreeNode<ElemType>* p, const ElemType& e);
    int Width() const;
};

template <class ElemType>
Tree<ElemType>::Tree()
{
    root = NULL;
}

template <class ElemType>
Tree<ElemType>::~Tree()
{
    Destroy(root);
}

template <class ElemType>
void Tree<ELemType>::Destroy(TreeNode<ElemType>*& r)
{
    if (r != NULL)
    {
        Destroy(r->firstchild);
        Destroy(r->nextsibling);
        delete r;
        r = NULL;
    }
}

template <class ElemType>
int Tree<ElemType>::Width()
{
    std::queue<ElemType*> q;
    if (root == NULL) return 0;
    q.push(root);
    int n = 1, ans = 1, cnt = 0;
    while (!q.empty())
    {
        for (int i = 0; i < n; i++)
        {
            TreeNode<ElemType>* p = q.front();
            q.pop();
            p = p->firstchild;
            while (p != NULL)
            {
                q.push(p);
                cnt++;
                p = p->nextsibling;
            }
        }
        ans = max(n = cnt, ans);
    }
    return ans;
}

template <class ELemType>
void Tree<ElemType>::InsertChild(TreeNode<ElemType>* p, const ElemType& e)
{
    if (p == NULL) return;
    TreeNode<ElemType>* child = new TreeNode<ElemType>(e);
    if (p->firstchild != NULL) child->firsthild = p->firstchild;
    p->firstchild = child;
}

template <class ElemType>
void Tree<ElemType>::InsertSibling(TreeNode<ElemType>* p, const ElemType& e)
{
    if (p == NULL) return;
    TreeNode<ElemType>* child = new TreeNode<ElemType>(e);
    if (p->nextsibling != NULL) child->nextsibling = p->nextsibling;
    p->nextsibling = child;
}

#endif