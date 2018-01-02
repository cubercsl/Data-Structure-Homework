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
    Status GetElem(int position, ElemType& e) const;     // 求指定位置的元素
    Status SetElem(int position, const ElemType& e);     // 设置指定位置的元素值
    Status DeleteElem(int position, ElemType& e);        // 删除元素
    Status InsertElem(int position, const ElemType &e);	 // 在指定位置插入元素
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
Status LinkList<ElemType>::GetElem(int i, ElemType& e) const
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    Node<ElemType>* p = head->next;
    int count;
    for (count = 1; count < i; count++)
        p = p->next; // p指向第i个结点
    e = p->data;     // 用e返回第i个元素的值
    return ENTRY_FOUND;
}

template <class ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType& e)
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    else
    {
        Node<ElemType>* p = head->next;
        int count;
        for (count = 1; count < i; count++)
            p = p->next; // 取出指向第i个结点的指针
        p->data = e;     // 修改第i个元素的值为e
        return SUCCESS;
    }
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType& e)
{
    if (i < 1 || i > length)
        return RANGE_ERROR; // i范围错
    Node<ElemType>*p = head, *q;
    int count;
    for (count = 1; count < i; count++)
        p = p->next;   // p指向第i-1个结点
    q = p->next;       // q指向第i个结点
    p->next = q->next; // 删除结点
    e = q->data;       // 用e返回被删结点元素值
    length--;          // 删除成功后元素个数减1
    delete q;          // 释放被删结点
    return SUCCESS;
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType& e)
{
    if (i < 1 || i > length + 1)
        return RANGE_ERROR;
    Node<ElemType>*p = head, *q;
    int count;
    for (count = 1; count < i; count++)
        p = p->next;                    // p指向第i-1个结点
    q = new Node<ElemType>(e, p->next); // 生成新结点q
    assert(q != 0);                     // 申请结点失败，终止程序运行
    p->next = q;                        // 将q插入到链表中
    length++;                           // 插入成功后，单链表长度加1
    return SUCCESS;
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
