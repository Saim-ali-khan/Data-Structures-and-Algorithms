#include <iostream>

using namespace std;

class Stack
{
private:
    int data[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(int dat)
    {
        if (top < 9)
        {
            top++;
            data[top] = dat;
        }
        else
        {
            cout << "\nStack Overflow";
            getchar();
        }
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            cout << "\nStack Underflow";
        }
    }
    int peek()
    {
        if (top != -1)
        {
            return data[top];
        }
        else
        {
            cout << "\nStack is Empty";
        }
    }

    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isFull()
    {
        if (top == 9)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int length()
    {
        return top + 1;
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << data[i] << "  ";
        }
    }
};

int main()
{
    Stack st1;
    cout<<st1.isEmpty()<<" "<<st1.isFull();
    st1.push(45);
    st1.push(23);
    st1.push(2);
    st1.push(3);
    st1.push(3);
    st1.push(3);

    cout << "Length :  " << st1.length() << "\n";
    st1.print();
}