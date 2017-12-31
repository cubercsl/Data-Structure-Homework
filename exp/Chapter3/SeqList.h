#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#include "Assistance.h"

template <class ElemType>
class SeqList
{
protected:
    int length;      // 顺序表的当前长度
    int maxLength;   // 顺序表的最大容量
    ElemType* elems; // 元素存储空间的首地址

public:
    SeqList(int size = DEFAULT_SIZE);                                  // 构造一个空表
    SeqList(ElemType v[], int n, int size = DEFAULT_SIZE);             // 根据数组v的内容构造顺序表
    virtual ~SeqList();                                                // 析构函数
    int GetLength() const;                                             // 取顺序表长度
    void Traverse(void (*Visit)(const ElemType&)) const;               // 遍历顺序表
    Status GetElem(int i, ElemType& e) const;                          // 取顺序表中第i个元素的值
    Status DeleteElem(int i, ElemType& e);                             // 删除顺序表中第i个元素
    Status DeleteMinElem(ElemType& e);                                 // 在顺序表中删除具有最小值的元素(1)
    void DelElem(const ElemType& e);                                   // 从顺序表中删除具有给定值e的所有元素(1)
    void DelRepElem();                                                 // 从顺序表中删除重复元素(1)
    Status InsertElem(const ElemType& e);                              // 在有序顺序表中插入元素(2)
    void DeleteElem(const ElemType& e);                                // 在有序顺序表中删除值为e的所有元素(2)
    SeqList(const SeqList<ElemType>& la, const SeqList<ElemType>& lb); // 由两个顺序表合并构造一个新的有序表(2)
    void DeleteElemBetweenSandT(ElemType s, ElemType t);               // 从有序顺序表中删除其值在给定值之间的所有元素(2)
    void Inverse();                                                    // 在顺序表上进行原地逆置(3)
};

template <class ElemType>
SeqList<ElemType>::SeqList(int size)
{
    elems = new ElemType[size];
    assert(elems);
    maxLength = size;
    length = 0;
}

template <class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int n, int size)
{
    elems = new ElemType[size];
    assert(elems);
    maxLength = size;
    length = n;
    for (int i = 0; i < length; i++) elems[i] = v[i];
}

template <class ElemType>
SeqList<ElemType>::~SeqList()
{
    delete[] elems;
}

template <class ElemType>
int SeqList<ElemType>::GetLength() const
{
    return length;
}

template <class ElemType>
void SeqList<ElemType>::Traverse(void (*Visit)(const ElemType&)) const
{
    for (int i = 0; i < length; i++)
        (*Visit)(elems[i]);
}

template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType& e) const
{
    if (i < 1 || i > length)
        return NOT_PRESENT;
    else
    {
        e = elems[i - 1];
        return ENTRY_FOUND;
    }
}

template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType& e)
{
    if (i < 1 || i > length)
        return RANGE_ERROR;
    else
    {
        e = elems[i - 1];
        for (int j = i; j < length; j++) elems[j - 1] = elems[j];
        length--;
        return SUCCESS;
    }
}

template <class ElemType>
Status SeqList<ElemType>::DeleteMinElem(ElemType& e)
{
    if (length == 0)
        return UNDER_FLOW;
    int k = 0;
    for (int i = 1; i < length; i++)
        if (elems[i] < elems[k]) k = i;
    e = elems[k];
    elems[k] = elems[--length];
    return SUCCESS;
}

template <class ElemType>
void SeqList<ElemType>::DelElem(const ElemType& e)
{
    ElemType x;
    for (int i = 1; i <= length; i++)
    {
        GetElem(i, x);
        if (x == e) DeleteElem(i--, x);
    }
}

template <class ElemType>
void SeqList<ElemType>::DelRepElem()
{
    ElemType x, y;
    for (int i = 1; i <= length; i++)
    {
        GetElem(i, x);
        for (int j = i + 1; j <= length; j++)
        {
            GetElem(j, y);
            if (x == y)
                DeleteElem(j--, x);
        }
    }
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType& e)
{
    if (length == this->maxLength) return OVER_FLOW;
    int i;
    for (i = length; i && elems[i - 1] > e; i--)
        elems[i] = elems[i - 1];
    elems[i] = e;
    length++;
    return SUCCESS;
}

template <class ElemType>
void SeqList<ElemType>::DeleteElem(const ElemType& e)
{
    int i = 0, j;
    while (i < length && elems[i] < e) i++;
    if (i == length || elems[i] != e) return;
    j = i + 1;
    while (j < length && elems[i] == e) j++;
    while (j <= length) elems[i++] = elems[j++];
    length -= (j - i);
}

template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList& la, const SeqList& lb)
{
    int a_Length = la.GetLength();
    int b_Length = lb.GetLength();
    ElemType e1, e2;
    this->maxLength = max(la.maxLength, lb.maxLength) << 1;
    elems = new ElemType[this->maxLength];
    assert(elems);
    length = 0;
    la.GetElem(1, e1);
    lb.GetElem(1, e2);
    int i = 1, j = 1;
    while (i <= a_Length && j <= b_Length)
    {

        if (e1 < e2)
        {
            elems[length++] = e1;
            la.GetElem(++i, e1);
        }
        else
        {
            elems[length++] = e2;
            lb.GetElem(++j, e2);
        }
    }
    while (i <= a_Length)
    {
        elems[length++] = e1;
        la.GetElem(++i, e1);
    }
    while (j <= b_Length)
    {
        elems[length++] = e2;
        lb.GetElem(++j, e2);
    }
}

template <class ElemType>
void SeqList<ElemType>::DeleteElemBetweenSandT(ElemType s, ElemType t)
{
    assert(s < t);
    int i = 0, j;
    while (i < length && elems[i] < s) i++;
    j = i + 1;
    while (j < length && elems[j] <= t) j++;
    while (j <= length) elems[i++] = elems[j++];
    length -= (j - i);
}

template <class ElemType>
void SeqList<ElemType>::Inverse()
{
    for (int i = 0; i < length / 2; i++)
        swap(elems[i], elems[length - i - 1]);
}

#endif