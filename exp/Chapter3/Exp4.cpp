#include "LinkList.h"
using namespace std;

int main()
{
    int a[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 10;
    cout << "LinkList:" << endl;
    LinkList<int> List_A(a, 10);
    List_A.Traverse(Write);
    cout << endl;
    int i = rand() % 10;
    cout << "LocateElem " << i << ":" << endl;
    Node<int>* p = List_A.LocateElem(i);
    cout << p << " -> data:" << p->data << endl;
    int e = rand() % 10;
    cout << "CountElem " << e << ": ";
    cout << List_A.CountElem(e) << endl;
    return 0;
}