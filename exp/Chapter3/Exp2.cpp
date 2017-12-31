#include "SeqList.h"
#include <algorithm> //sort
using namespace std;

int main()
{
    srand(time(NULL));
    int a[10], b[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 10, b[i] = rand() % 10;
    sort(a, a + 10);
    sort(b, b + 10);

    SeqList<int> List_A(a, 10);
    SeqList<int> List_B(b, 10);

    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    int e = rand() % 10;
    cout << "InsertElem " << e << ":" << endl;
    List_A.InsertElem(e);
    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    int f = rand() % 10;
    cout << "DeleteElem " << f << ":" << endl;
    List_A.DeleteElem(f);
    List_A.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    List_A.Traverse(Write);
    cout << endl;
    List_B.Traverse(Write);
    cout << endl;
    cout << "After Merge：" << endl;
    SeqList<int> List_C(List_A, List_B);
    List_C.Traverse(Write);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "DeleteElemBetweenSandT(3, 7):" << endl;
    List_C.DeleteElemBetweenSandT(3, 7);
    List_C.Traverse(Write);
    cout << endl;

    return 0;
}