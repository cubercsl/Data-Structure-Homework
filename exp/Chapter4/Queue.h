#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stack>
using std::stack;

template <class T>
class Queue
{
private:
    stack<T> s1, s2;

public:
    void push(const T& e); // 入队
    T pop();               // 出队
    bool empty() const;    // 判空
};

template <class T>
void Queue<T>::push(const T& e) { s1.push(e); }

template <class T>
T Queue<T>::pop()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    T ret = s2.top();
    s2.pop();
    return ret;
}

template <class T>
bool Queue<T>::empty() const { return s1.empty() && s2.empty(); }

#endif