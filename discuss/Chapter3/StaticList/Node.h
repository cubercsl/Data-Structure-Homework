#ifndef __NODE_H__
#define __NODE_H__

template <class ElemType>
struct Node
{
    ElemType data; // 数据域
    int next;      // 指针域

    Node();                                 // 无参数的构造函数
    Node(const ElemType& e, int link = -1); // 已知数数据元素值和指针建立结构
};

template <class ElemType>
Node<ElemType>::Node()
{
    next = -1;
}

template <class ElemType>
Node<ElemType>::Node(const ElemType& e, int link)
{
    data = e;
    next = link;
}

#endif
