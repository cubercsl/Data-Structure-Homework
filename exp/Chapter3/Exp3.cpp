#include "LinkList.h"
#include "SeqList.h"
using namespace std;

int main()
{
    int a[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 10;
    cout << "SeqList:" << endl;
    SeqList<int> List_A(a, 10);
    List_A.Traverse(Write);
    cout << endl;
    cout << "Inverse:" << endl;
    List_A.Inverse();
    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "LinkList:" << endl;
    LinkList<int> List_B(a, 10);
    List_B.Traverse(Write);
    cout << endl;
    cout << "Inverse:" << endl;
    List_B.Inverse();
    List_B.Traverse(Write);
    cout << endl;
    return 0;
}
