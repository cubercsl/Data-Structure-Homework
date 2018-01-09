#ifndef __LK_LIST2_H__
#define __LK_LIST2_H__

#include "Assistance.h" // 辅助软件包
#include "Node.h"       // 结点类

template <class ElemType>
class LinkList
{
protected:
    //  单链表的数据成员
    Node<ElemType>* head; // 头指针
    int length;           // 单链表长度

public:
    //  单链表的函数成员
    LinkList();                                          // 无参数的构造函数
    LinkList(ElemType v[], int n);                       // 根据数组内容构造链表
    virtual ~LinkList();                                 // 析构函数
    int GetLength() const;                               // 求单链表长度
    bool IsEmpty() const;                                // 判断单链表是否为空
    void Clear();                                        // 将单链表清空
    void Traverse(void (*Visit)(const ElemType&)) const; // 遍历单链表
    Status InsertElem(int pos, const ElemType& e);       // 在指定位置插入元素(5)
    Status DeleteElem(int pos, ElemType& e);             // 删除指定位置元素(5)
    void Merge(LinkList& b);                             // 合并得到递减链表(10)
};

template <class ElemType>
LinkList<ElemType>::LinkList()
{
    head = NULL;
    length = 0;
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n)
{
    Node<ElemType>* p;
    p = head = new Node<ElemType>(v[0], NULL);
    assert(head != 0);
    for (int i = 1; i < n; i++)
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
    Clear();     // 清空单链表
    delete head; // 释放头结点所指空间
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
    return length;
}

template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
{
    return head == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
{
    Node<ElemType>* p = head;
    while (p != NULL)
    {
        head = p->next;
        delete p;
        p = head;
    }
    length = 0;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
{
    Node<ElemType>* p = head;
    while (p != NULL)
    {
        (*Visit)(p->data);
        p = p->next;
    }
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int pos, const ElemType& e)
{
    if (pos < 1 || pos > length + 1) return RANGE_ERROR;
    Node<ElemType>*p, *q;
    if (pos == 1)
    {
        q = new Node<ElemType>(e, head);
        head = q;
    }
    else
    {
        p = head;
        for (int i = 2; i < pos; i++) p = p->next;
        q = new Node<ElemType>(e, p->next);
        p->next = q;
    }
    length++;
    return SUCCESS;
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int pos, ElemType& e)
{
    if (pos < 1 || pos > length) return RANGE_ERROR;
    Node<ElemType>*p, *q;
    if (pos == 1)
    {
        q = head;
        head = head->next;
    }
    else
    {
        p = head;
        for (int i = 2; i < pos; i++) p = p->next;
        q = p->next;
        p->next = q->next;
    }
    e = q->data;
    delete q;
    return SUCCESS;
}

template <class ElemType>
void LinkList<ElemType>::Merge(LinkList<ElemType>& b)
{
    Node<ElemType>*pa, *pb, *q;
    pa = head, pb = b.head;
    head = NULL;
    b.head = NULL;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data <= pb->data)
            q = pa, pa = pa->next;
        else
            q = pb, pb = pb->next;
        q->next = head, head = q; // 在头部插入
    }
    while (pa != NULL)
    {
        q = pa, pa = pa->next;
        q->next = head, head = q;
    }
    while (pb != NULL)
    {
        q = pb, pb = pb->next;
        q->next = head, head = q;
    }
    length += b.length;
    b.length = 0;
}

#endif
