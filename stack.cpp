#include <bits/stdc++.h>
#define n 25
using namespace std;

class stack1
{

    int *arr;
    int top;

public:
    stack1()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
        }
        top--;
    }
    int Top()
    {
        return (arr[top]);
    }
};

int main()
{
    stack1 s1;
    s1.push(25);
    cout << s1.Top() << endl;
    s1.push(24);
    s1.push(23);
    s1.pop();
    cout << s1.Top();

    return 0;
}
