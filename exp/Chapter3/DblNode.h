#ifndef __DBL_NODE_H__
#define __DBL_NODE_H__

template <class ElemType>
struct DblNode
{
    ElemType data;            // 数据域
    int freq;                 // 访问频度
    DblNode<ElemType>* prior; // 指向前驱结点的指针域
    DblNode<ElemType>* next;  // 指向后继结点的指针域

    DblNode(); // 无数据的构造函数
    DblNode(ElemType item,
            DblNode<ElemType>* priorlink = NULL,
            DblNode<ElemType>* nextlink = NULL); // 已知数据域和指针域建立结构
};

template <class ElemType>
DblNode<ElemType>::DblNode()
{
    freq = 0;
    prior = NULL;
    next = NULL;
}

template <class ElemType>
DblNode<ElemType>::DblNode(ElemType item,
                           DblNode<ElemType>* priorlink,
                           DblNode<ElemType>* nextlink)
{
    data = item;
    freq = 0;
    prior = priorlink;
    next = nextlink;
}

#endif
