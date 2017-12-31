#ifndef __NODE_H__
#define __NODE_H__

template <class ElemType>
struct Node
{
    ElemType data;        // 数据域
    Node<ElemType>* next; // 指针域

    Node();                                        // 无参数的构造函数
    Node(ElemType e, Node<ElemType>* link = NULL); // 已知数数据元素值和指针建立结构
};

template <class ElemType>
Node<ElemType>::Node()
{
    next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link)
{
    data = e;
    next = link;
}

#endif
