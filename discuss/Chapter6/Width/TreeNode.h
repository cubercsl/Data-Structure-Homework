#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

template <class ElemType>
struct TreeNode
{
    ElemType data;
    TreeNode<ElemType>* firstchild;
    TreeNode<ElemType>* nextsibling;

    TreeNode();
    TreeNode(const ElemType& d,
                TreeNode<ElemType>* firstchild = NULL,
                TreeNode<ElemType>* nextsibling = NULL);
};

template <class ElemType>
TreeNode<ElemType>::TreeNode()
{
    firstchild = nextsibling = NULL;
}

template <class ElemType>
TreeNode<ElemType>::TreeNode(const ElemType& d,
                                   TreeNode<ElemType>* _firstchild, TreeNode<ElemType>* _nextsibling)
{
    data = d;
    firstchild = _firstchild;
    nextsibling = _nextsibling;
}

#endif
