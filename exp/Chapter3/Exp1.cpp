#include "SeqList.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 10;

    SeqList<int> List_A(a, 10);

    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "DeleteMinElem:" << endl;
    int e;
    List_A.DeleteMinElem(e);
    cout << e << endl;
    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    char c = rand() % 10;
    cout << "DelElem " << c << " :" << endl;
    List_A.DelElem(c);
    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "DelRepElem:" << endl;
    List_A.DelRepElem();
    List_A.Traverse(Write);
    cout << endl;
    return 0;
}
