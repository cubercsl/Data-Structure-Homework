#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "Assistance.h"
#include "LinkList.h"
#include "PolyItem.h"

class Polynomial
{
protected:
    LinkList<PolyItem> polyList; // 多项式组成的线性表

public:
    Polynomial(){};                     // 无参构造函数
    ~Polynomial(){};                    // 析构函数
    int Length() const;                 // 求多项式的项数
    bool IsZero() const;                // 判断多项式是否为0
    void SetZero();                     // 将多项式置为0
    void Display();                     // 显示多项式
    void InsItem(const PolyItem& item); // 插入一项
    Polynomial(const Polynomial& copy); // 复制构造函数
    Polynomial(const LinkList<PolyItem>& copyLinkList);
    // 由多项式组成的线性表构造多项式
    Polynomial& operator=(const Polynomial& copy);                 // 赋值语句重载
    Polynomial& operator=(const LinkList<PolyItem>& copyLinkList); // 赋值语句重载
    Polynomial(PolyItem v[], int n);                               // 由数组内容构造多项式
    double Calc(double x);                                         // 计算多项式的值(7)
    void Derivative();                                             // 多项式求导(8)
};

int Polynomial::Length() const
{
    return polyList.GetLength();
}

bool Polynomial::IsZero() const
{
    return polyList.IsEmpty();
}

void Polynomial::SetZero()
{
    polyList.Clear();
}

void Polynomial::Display()
{
    int pos = 1;
    PolyItem it;
    Status status = polyList.GetElem(pos, it);
    while (status == ENTRY_FOUND)
    {
        if (pos > 1 && it.coef > 0)
            cout << "+";
        if (it.coef != 1)
            if (it.coef != -1)
                cout << it.coef;
            else
                cout << "-";
        if (it.expn > 1)
            cout << "x^" << it.expn;
        else if (it.expn == 1)
            cout << "x";
        status = polyList.GetElem(++pos, it);
    }
}

void Polynomial::InsItem(const PolyItem& item)
{
    int pos = 1;
    PolyItem it;
    Status status = polyList.GetElem(pos, it);
    while (status == ENTRY_FOUND && it.expn > item.expn)
        status = polyList.GetElem(++pos, it);
    polyList.InsertElem(pos, item);
}

Polynomial::Polynomial(const Polynomial& copy)
{
    polyList = copy.polyList;
}

Polynomial::Polynomial(const LinkList<PolyItem>& copyLinkList)
{
    polyList = copyLinkList;
}

Polynomial& Polynomial::operator=(const Polynomial& copy)
{
    if (&copy != this) {
        polyList = copy.polyList;
    }
    return *this;
}

Polynomial& Polynomial::operator=(const LinkList<PolyItem>& copyLinkList)
{
    polyList = copyLinkList;
    return *this;
}

Polynomial::Polynomial(PolyItem v[], int n)
{
    polyList.Clear();
    for (int i = 0; i < n; i++)
        InsItem(v[i]);
}

inline double Pow(double x, int n)
{ // 快速幂
    double ret = 1;
    for (; n; n >>= 1, x *= x)
        if (n & 1) ret *= x;
    return ret;
}

double Polynomial::Calc(double x)
{
    PolyItem it;
    double ret = 0;
    for (int i = 1; i <= Length(); i++)
    {
        polyList.GetElem(i, it);
        ret += it.coef * Pow(x, it.expn);
    }
    return ret;
}

void Polynomial::Derivative()
{
    PolyItem it;
    for (int i = 1; i <= Length(); i++)
    {
        polyList.GetElem(i, it);
        if (it.expn == 0)
            polyList.DeleteElem(i, it);
        else
        {
            it.coef = it.coef * it.expn, it.expn--;
            polyList.SetElem(i, it);
        }
    }
}

#endif
