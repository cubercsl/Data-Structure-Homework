#include "DblLinkList.h"
using namespace std;

int main()
{
    int a[10], x = 0;
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 10 + 1;
    DblLinkList<int> List(a, 10);
    List.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;
    for (; ~x;)
    {
        cout << "Locate: ";
        cin >> x;
        int pos = List.LocateElem(x);
        if (pos)
            cout << "pos: " << pos << endl;
        else
            cout << "NOT FOUND!" << endl;
        List.Traverse(Write);
        cout << endl;
        cout << "--------------------" << endl;
    }
}