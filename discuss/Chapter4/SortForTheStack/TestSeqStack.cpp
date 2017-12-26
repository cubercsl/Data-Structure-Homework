#include "SeqStack.h"	// 顺序栈类
#include "SeqQueue.h"   // 循环队列类

int main(void)
{
    char c = '1';
    SeqStack<int> sa;
    int x;

    while (c != '0')
    {
        cout << endl << "1. 生成栈.";
        cout << endl << "2. 显示栈.";
        cout << endl << "3. 入栈.";
        cout << endl << "4. 出栈.";
        cout << endl << "5. 取栈顶.";
        cout << endl << "6. 自底向顶a1a2...a2n排序为a1a3...a(2n-1)a2a4...a2n.";
        cout << endl << "0. 退出";
        cout << endl << "选择功能(0~6):";
        cin >> c;
        switch (c)
        {
        case '1':
            sa.Clear();
            cout << "输入e(e = 0时退出)" << endl ;
            cin >> x;
            while (x != 0)
            {
                sa.Push(x);
                cin >> x;
            }
            break;
        case '2':
            cout << endl;
            sa.Traverse(Write<int>);
            break;
        case '3':
            cout << endl << "输入元素值:";
            cin >> x;
            if (sa.Push(x) == SUCCESS)
                cout << endl << "入栈成功." << endl;
            else
                cout << endl << "空间不够，入栈失败." << endl;
            break;
        case '4':
            if (sa.Pop(x) == SUCCESS)
                cout << endl << "栈顶元素值为：" << x << "." << endl;
            else
                cout << endl << "栈为空。 " << endl;
            break;
        case '5':
            if (sa.Top(x) == SUCCESS)
                cout << endl << "栈顶元素值为：" << x << "." << endl;
            else
                cout << endl << "栈为空。 " << endl;
            break;
        case '6':
            //先输入生成a1a2...a2n栈
            cout << "请输入a1a2...a2n" << endl;
            sa.Clear();
            cout << "输入e(e = 0时退出)" << endl ;
            cin >> x;
            while (x != 0)
            {
                sa.Push(x);
                cin >> x;
            }

            //第一步把栈中数全部取出放到队列，在队列中变成a2na(2n-1)...a2a1
            SeqQueue<int> q;
            while(!sa.IsEmpty())
            {
                int temp;
                sa.Pop(temp);
                q.EnQueue(temp);
            }

            //然后将偶数放入栈，即变为状态：栈中a2n,a(2n-2)...a4,a2 队列中a(2n-1),a(2n-3)...a3,a1
            int length=q.GetLength();
            for(int i=0;i<length;++i)
            {
                int temp;
                q.DelQueue(temp);
                if(temp%2) q.EnQueue(temp);
                else sa.Push(temp);
            }

            //再将队列中的奇数都放入栈：栈中a2n,a(2n-2)...a4,a2,a(2n-1),a(2n-3),...,a3,a1
            while(!q.IsEmpty())
            {
                int temp;
                q.DelQueue(temp);
                sa.Push(temp);
            }

            //再将栈中所有元素放入队列
            while(!sa.IsEmpty())
            {
                int temp;
                sa.Pop(temp);
                q.EnQueue(temp);
            }

            //最后将队列中所有元素放入栈中
            while(!q.IsEmpty())
            {
                int temp;
                q.DelQueue(temp);
                sa.Push(temp);
            }

            break;
        }
    }

    system("PAUSE");
    return 0;
}


