#include <bits/stdc++.h>
#define n 25
using namespace std;

class q
{

    int *arr;
    int front;
    int back;

public:
    q()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        back++;
        arr[back] = val;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        return (arr[front]);
    }
};

int main()
{
    q q1;
    q1.push(25);
    q1.push(24);
    cout << q1.peek() << endl;
    q1.push(23);
    q1.pop();
    cout << q1.peek();

    return 0;
}
