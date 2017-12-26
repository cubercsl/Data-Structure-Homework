#include <bits/stdc++.h>
using namespace std;

map<char, int> M;

string change(const string& str)
{
    string ret;
    stack<char> s;
    s.push('#');
    for (int i = 0; i < str.length(); i++)
    {
        char t = str[i];
        if (t == '(')
            s.push(t);
        else if (t == ')')
        {
            while (s.top() != '(')
            {
                ret += s.top();
                s.pop();
                ret += ' ';
            }
            s.pop();
        }
        else if (t == '+' || t == '-' || t == '*' || t == '/')
        {
            while (M[s.top()] >= M[t])
            {
                ret += s.top();
                ret += ' ';
                s.pop();
            }
            s.push(t);
        }
        else
        {
            while (isdigit(str[i]))
                ret += str[i++];
            i--, ret += ' ';
        }
    }
    while (s.top() != '#')
    {
        ret += s.top();
        ret += ' ';
        s.pop();
    }
    return ret;
}
int solve(const string& str)
{
    stack<int> s;
    int i = 0, tmp;
    while (i < str.length())
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        if (str[i] == '+')
            tmp = s.top(), s.pop(), tmp += s.top(), s.pop(), i++;
        else if (str[i] == '-')
            tmp = s.top(), s.pop(), tmp = s.top() - tmp, s.pop(), i++;
        else if (str[i] == '*')
            tmp = s.top(), s.pop(), tmp *= s.top(), s.pop(), i++;
        else if (str[i] == '/')
            tmp = s.top(), s.pop(), tmp = s.top() / tmp, s.pop(), i++;
        else
        {
            tmp = 0;
            while (isdigit(str[i]))
                tmp = tmp * 10 + str[i++] - '0';
        }
        s.push(tmp);
    }
    return s.top();
}
int main()
{
    M['+'] = 1, M['-'] = 1, M['*'] = 2, M['/'] = 2;
    string s;
    while (cin >> s)
    {
        string postorder = change(s);
        // cout << postorder << endl;
        cout << solve(postorder) << endl;
    }
    return 0;
}
