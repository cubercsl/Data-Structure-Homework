#include <bits/stdc++.h>
using namespace std;

map<char, int> M;

inline void calc(stack<int>& num, char op)
{
    int tmp;
    if (op == '+')
        tmp = num.top(), num.pop(), tmp += num.top(), num.pop();
    else if (op == '-')
        tmp = num.top(), num.pop(), tmp = num.top() - tmp, num.pop();
    else if (op == '*')
        tmp = num.top(), num.pop(), tmp *= num.top(), num.pop();
    else if (op == '/')
        tmp = num.top(), num.pop(), tmp = num.top() / tmp, num.pop();
    num.push(tmp);
}

int solve(const string& str)
{
    stack<int> num;
    stack<char> op;
    op.push('#');
    int i = 0;
    char ope;
    while (i < str.length())
    {
        char t = str[i];
        if (t == '(')
            op.push(t), i++;
        else if (t == ')')
        {
            while (op.top() != '(')
            {
                calc(num, op.top());
                op.pop();
            }
            op.pop(), i++;
        }
        else if (t == '+' || t == '-' || t == '*' || t == '/')
        {
            while (M[op.top()] >= M[t])
            {
                calc(num, op.top());
                op.pop();
            }
            op.push(t), i++;
        }
        else
        {
            int tmp = 0;
            while (isdigit(str[i]))
                (tmp *= 10) += str[i++] - '0';
            num.push(tmp);
        }
    }
    while(op.top()!= '#')
    {
        calc(num, op.top());
        op.pop();
    }
    return num.top();
}

int main()
{
    M['+'] = 1, M['-'] = 1, M['*'] = 2, M['/'] = 2;
    string s;
    while (cin >> s)
        cout << solve(s) << endl;
    return 0;
}
