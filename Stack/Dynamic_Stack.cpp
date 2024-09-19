#include <iostream>

using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node *next;

public:
    Node(T dat)
    {
        data = dat;
        next = nullptr;
    }
    int giveData()
    {
        return data;
    }
    Node *giveNext()
    {
        return next;
    }
    void setNext(Node *node)
    {
        next = node;
    }
};

template <class X>
class Stack
{
private:
    Node<X> *top;
    int len;

public:
    Stack()
    {
        top = nullptr;
        len = 0;
    }
    Stack(X dat)
    {
    }
    void push(X dat)
    {
        Node<X> *ptr = new Node<X>(dat);
        if (top != nullptr)
        {
            Node<X> *temp = top;
            top->setNext(ptr);
            ptr->setNext(temp);
        }
        else
        {
            top = ptr;
        }
        len++;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "No element";
            len = 0;
        }
        else
        {
            Node<X> *ptt = top->giveNext();
            delete top;
            top = ptt;
            len--;
        }
    }
    X peek()
    {
        return top->giveData();
    }
    int length()
    {
        return len;
    }
    void print()
    {
        Node<X> *ptr = top;
        while (ptr != nullptr)
        {
            cout << X(ptr->giveData()) << "  ";
            ptr = ptr->giveNext();
        }
    }
};

bool operato(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        return true;
    }
    else
        return false;
}

int prec(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*')
    {
        return 2;
    }
    else if (c == '/')
    {
        return 3;
    }
    else 
        return -1;
}

int main()
{
    Stack<char> operators;
    char exp[8] = "a+b*c-d";
    char postexp[8];
    int k = 0;
    for (int i = 0; i < 7; i++)
    {
        if (! operato(exp[i]))
        {
            postexp[k] = exp[i];
            k++;
        }
        else
        {
            if (operators.length() == 0 || prec(operators.peek()) <= prec(exp[i]))
            {
                operators.push(exp[i]);
            }
            else if (prec(operators.peek()) > prec(exp[i]))
            {
                while (operators.length() != 0)
                {
                    postexp[k] = operators.peek();
                    operators.pop();
                    k++;
                    
                }
                operators.push(exp[i]);
            }
        }
    }
    while (operators.length() != 0)
    {
        postexp[k] = operators.peek();
        operators.pop();
        k++;
    }
    cout<<postexp;
}