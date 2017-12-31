#include "LinkList.h"
#include <algorithm>
using namespace std;

int main()
{
    srand(time(NULL));
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 10;
    sort(a, a + 10);
    LinkList<int> List_A(a, 10);

    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    int e = rand() % 10;
    cout << "InsertElem " << e << " :" << endl;
    List_A.InsertElem(e);
    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    int f = rand() % 10;
    cout << "DelElem " << f << " :" << endl;
    List_A.DeleteElem(f);
    List_A.Traverse(Write);
    cout << endl;

    return 0;
}