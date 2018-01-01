#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Queue<int> q;
    string op;
    int num;
    for (;;)
    {
        cout << "Please Input: ";
        cin >> op;
        if (op == "push")
        {
            cin >> num;
            cout << "push: " << num << endl;
            q.push(num);
        }
        else if (op == "pop")
        {
            if (!q.empty())
                cout << "pop: " << q.pop() << endl;
            else
                cout << "queue is empty!" << endl;
        }
    }
}