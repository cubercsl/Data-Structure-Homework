#include "LinkList2.h"
using namespace std;

int main()
{
    srand(time(0));
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 10 + 1;
    LinkList<int> List(a, 10);
    int op = -1, num, pos;
    List.Traverse(Write);
    cout << endl;
    for (; op;)
    {
        cout << "Please Input: ";
        // 1: insert
        // 2: delete
        cin >> op;
        if (op == 1)
        {
            cout << "Insert: ";
            cin >> pos >> num;
            if (List.InsertElem(pos, num) == SUCCESS)
            {
                cout << "SUCCESS" << endl;
                List.Traverse(Write);
                cout << endl;
            }
            else
                cout << "RANGE ERROR" << endl;
        }
        else if (op == 2)
        {
            cout << "Delete: ";
            cin >> pos;
            if (List.DeleteElem(pos, num) == SUCCESS)
            {
                cout << "SUCCESS Delete " << num << endl;
                List.Traverse(Write);
                cout << endl;
            }
            else
                cout << "RANGE ERROR" << endl;
        }
    }
    return 0;
}