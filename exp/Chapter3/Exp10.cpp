#include "LinkList2.h"
#include <algorithm> //sort
using namespace std;

int main()
{
    srand(time(0));
    int a[10], b[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 10 + 1, b[i] = rand() % 10 + 1;
    sort(a, a + 10);
    sort(b, b + 10);
    LinkList<int> List_A(a, 10);
    LinkList<int> List_B(b, 10);
    cout << "A: ";
    List_A.Traverse(Write);
    cout << endl;
    cout << "B: ";
    List_B.Traverse(Write);
    cout << endl;
    List_A.Merge(List_B);
    cout << "Merge: ";
    List_A.Traverse(Write);
    cout << endl;
}