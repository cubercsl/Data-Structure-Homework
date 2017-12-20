#include "StaticList.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 10;
    StaticList<int> list(a, 10, 12);
    int op, num, e;
    cout << "主菜单" << endl;
    cout << "1. 清空静态链表" << endl;
    cout << "2. 在头部插入元素" << endl;
    cout << "3. 删除指定位置元素" << endl;
    cout << "0. 退出" << endl;
    while (op != 0)
    {
        if (list.IsEmpty())
            cout << "当前链表为空" << endl;
        else
        {
            cout << "当前链表长度为:" << list.GetLength() << endl;
            list.Traverse(Write);
            cout << endl;
        }
#ifdef DEBUG
        list.debug();
#endif
        cout << "请选择功能：";
        cin >> op;
        switch (op)
        {
        case 1: list.Clear(); break;
        case 2:
            cout << "请输入要插入的元素: ";
            cin >> num;
            if (list.InsertElem(num) == OVER_FLOW)
                cout << "静态链表空间已满" << endl;
            else
                cout << "插入成功" << endl;
            break;
        case 3:
            cout << "请输入要删除的位置: ";
            cin >> num;
            if (list.DeleteElem(num, e) == RANGE_ERROR)
                cout << "输入范围错误" << endl;
            else
                cout << "删除元素 " << e << " 成功" << endl;
        }
    }
    return 0;
}