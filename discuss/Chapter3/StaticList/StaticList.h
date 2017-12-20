#ifndef __ST_LIST_H__
#define __ST_LIST_H__

#include "Assistance.h"
#include "Node.h"

template <class ElemType>
class StaticList
{
protected:
    int head;              // 头指针
    int avail;             // 可分配结点下标
    int length;            // 静态链表的当前长度
    int maxLength;         // 静态链表的最大长度
    Node<ElemType>* elems; // 数据成员

public:
    StaticList(int size = DEFAULT_SIZE);                      // 创建一个空表
    StaticList(ElemType v[], int n, int size = DEFAULT_SIZE); // 根据数组v的内容创建静态链表
    virtual ~StaticList();                                    // 析构函数
    int GetLength() const;                                    // 取静态链表长度
    bool IsEmpty() const;                                     // 判断链表是否为空
    void Clear();                                             // 清空链表
    void Traverse(void (*Vist)(const ElemType&)) const;       // 遍历静态链表
    Status InsertElem(const ElemType& e);                     // 在表头插入元素
    Status DeleteElem(int i, ElemType& e);                    // 删除指定位置的元素
    StaticList<ElemType>& operator=(const StaticList& list);  // 重载赋值运算符
    StaticList(const StaticList& list);                       // 拷贝构造函数

#ifdef DEBUG
    void debug()
    {
        for (int i = 0; i < maxLength; i++)
            printf("data[%2d] = %d,\tnext[%2d] = %d\n", i, elems[i].data, i, elems[i].next);
    }
#endif
};

template <class ElemType>
StaticList<ElemType>::StaticList(int size)
{
    elems = new Node<ElemType>[size];
    assert(elems);
    head = 0;
    length = 0;
    maxLength = size;
    for (int i = 0; i < size - 1; i++) elems[i].next = i + 1;
    avail = 1;
}

template <class ElemType>
StaticList<ElemType>::StaticList(ElemType v[], int n, int size)
{
    elems = new Node<ElemType>[size];
    assert(elems);
    head = 0;
    length = n;
    maxLength = size;
    for (int i = 0; i < size - 1; i++) elems[i].next = i + 1;
    for (int i = 0; i < n; i++) elems[i + 1].data = v[i];
    elems[n].next = -1;
    avail = n + 1;
}

template <class ElemType>
StaticList<ElemType>::~StaticList()
{
    delete[] elems;
}

template <class ElemType>
int StaticList<ElemType>::GetLength() const
{
    return length;
}

template <class ElemType>
bool StaticList<ElemType>::IsEmpty() const
{
    return elems[head].next == avail;
}

template <class ElemType>
void StaticList<ElemType>::Clear()
{
    int p = elems[head].next;
    while (~p && p != avail)
    {
        elems[head].next = elems[p].next;
        elems[p].next = avail;
        avail = p;
        p = elems[head].next;
    }
    elems[head].next = avail;
    length = 0;
}

template <class ElemType>
void StaticList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
{
    int p = elems[head].next;
    while (~p && p != avail)
    {
        (*Visit)(elems[p].data);
        p = elems[p].next;
    }
}

template <class ElemType>
Status StaticList<ElemType>::InsertElem(const ElemType& e)
{
    int p = avail;
    if (avail == -1) return OVER_FLOW;
    avail = elems[p].next;
    elems[p].data = e;
    if (elems[head].next == p)
        elems[p].next = -1;
    else
        elems[p].next = elems[head].next;

    elems[head].next = p;
    length++;
    return SUCCESS;
}

template <class ElemType>
Status StaticList<ElemType>::DeleteElem(int i, ElemType& e)
{
    if (i < 1 || i > length) return RANGE_ERROR;
    int p = head, q;
    int count;
    for (count = 1; count < i; count++) p = elems[p].next;
    q = elems[p].next;
    e = elems[q].data;
    if (elems[q].next == -1 && p == head)
        elems[p].next = q;
    else
        elems[p].next = elems[q].next;
    elems[q].next = avail;
    avail = q;
    length--;
    return SUCCESS;
}

template <class ElemType>
StaticList<ElemType>& StaticList<ElemType>::operator=(const StaticList& list)
{
    if (this == &list) return *this;
    delete[] elems;
    elems = new Node<ElemType>[maxLength = list.maxLength];
    length = list.length;
    head = list.head;
    avail = list.avail;
    for (int i = 0; i < maxLength; i++) elems[i] = list.elems[i];
    return *this;
}

template <class ElemType>
StaticList<ElemType>::StaticList(const StaticList& list)
{
    (*this) = list;
}

#endif