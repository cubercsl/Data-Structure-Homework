#include "Polynomial.h"

int main()
{
    PolyItem a[]={PolyItem(3,4),PolyItem(1,2)};
    PolyItem b[]={PolyItem(4,6),PolyItem(2,4),PolyItem(1,2)};


    Polynomial la(a,2),lb(b,3);
    Polynomial lc(a,2);
    Polynomial test;

    cout<<"有如下三个多项式,分别为："<<endl<<"la = ";
    la.Display();
    cout<<endl<<"lb = ";
    lb.Display();
    cout<<endl<<"lc = ";
    lc.Display();
    cout<<endl<<"将多项式lc清零后得到："<<endl<<"lc = ";
    lc.SetZero();
    lc.Display();
    cout<<endl<<"将多项式la与lb相加得到："<<endl<<"la + lb = ";
    test = la + lb;
    test.Display();
    cout<<endl<<"将多项式la与lb相减得到："<<endl<<"la - lb = ";
    test = la - lb;
    test.Display();
    cout<<endl<<"将多项式la与lb相乘得到："<<endl<<"la * lb = ";
    test = la * lb;
    test.Display();
    cout<<endl<<"将多项式la乘以整数3，得到："<<endl<<"la * 3 = ";
    test = la * 3;
    test.Display();
    getchar();
    return 0;
}
