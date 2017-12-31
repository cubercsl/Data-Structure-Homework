#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"
#include "Node.h"

template <class ElemType>
class LinkList
{
protected:
    Node<ElemType>* head; // 头结点指针
    int length;           // 单链表长度

public:
    LinkList();                                          // 无参数的构造函数
    LinkList(ElemType v[], int n);                       // 有参数的构造函数
    virtual ~LinkList();                                 // 析构函数
    int GetLength() const;                               // 求单链表长度
    bool IsEmpty() const;                                // 判断单链表是否为空
    void Clear();                                        // 将单链表清空
    void Traverse(void (*Visit)(const ElemType&)) const; // 遍历单链表
    void Inverse();                                      // 原地逆置(3)
    Node<ElemType>* LocateElem(int i) const;             // 寻找第i个结点(4)
    int CountElem(const ElemType& e) const;              // 统计单链表中等于给定值e的个数(4)
    void InsertElem(const ElemType& e);                  // 在有序单链表中插入元素(6)
    void DeleteElem(const ElemType& e);                  // 在有序单链表中删除元素等于e的结点(6)
};

template <class ElemType>
LinkList<ElemType>::LinkList()
{
    head = new Node<ElemType>;
    assert(head);
    length = 0;
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n)
{
    Node<ElemType>* p;
    p = head = new Node<ElemType>;
    assert(head != 0);
    for (int i = 0; i < n; i++)
    {
        p->next = new Node<ElemType>(v[i], NULL);
        assert(p->next);
        p = p->next;
    }
    length = n;
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    Clear();
    delete head;
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
    return length;
}

template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
{
    return head->next == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
{
    Node<ElemType>* p = head->next;
    while (p != NULL)
    {
        head->next = p->next;
        delete p;
        p = head->next;
    }
    length = 0;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
{
    Node<ElemType>* p = head->next;
    while (p != NULL)
    {
        (*Visit)(p->data);
        p = p->next;
    }
}

template <class ElemType>
void LinkList<ElemType>::Inverse()
{
    Node<ElemType>*p = head->next, *q;
    head->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

template <class ElemType>
Node<ElemType>* LinkList<ElemType>::LocateElem(int i) const
{
    Node<ElemType>* p;
    if (i < 1 || i > length) return NULL;
    p = head;
    for (; i; i--) p = p->next;
    return p;
}

template <class ElemType>
int LinkList<ElemType>::CountElem(const ElemType& e) const
{
    Node<ElemType>* p = head->next;
    int count = 0;
    while (p != NULL)
    {
        if (p->data == e) count++;
        p = p->next;
    }
    return count;
}

template <class ElemType>
void LinkList<ElemType>::InsertElem(const ElemType& e)
{
    Node<ElemType>*p = head, *q;
    while (p->next != NULL && p->next->data < e) p = p->next;
    q = new Node<ElemType>(e, p->next);
    p->next = q;
    length++;
}

template <class ElemType>
void LinkList<ElemType>::DeleteElem(const ElemType& e)
{
    Node<ElemType>*p = head, *q;
    while (p->next != NULL && p->next->data < e) p = p->next;
    while (p->next != NULL && p->next->data == e)
    {
        q = p->next;
        p->next = q->next;
        length--;
        delete q;
    }
}

#endif
