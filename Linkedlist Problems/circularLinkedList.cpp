#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *nxt;

public:
    Node(int dat)
    {
        data = dat;
        nxt = nullptr;
    }
    int giveData()
    {
        return data;
    }
    void setNext(Node *add)
    {
        nxt = add;
    }
    Node *Next()
    {
        return nxt;
    }
};
class CircularLinkedList
{
private:
    Node *head;
    int leng;

public:
    CircularLinkedList()
    {
        head = nullptr;
        leng = 0;
    }
    CircularLinkedList(Node *add)
    {
        head = add;
        add->setNext(add);
        leng = 1;
    }
    int length()
    {
        int len = 0;
        Node *temp = head->Next();
        while (temp != head)
        {
            len++;
            temp = temp->Next();
        }
        len++;
        return len;
    }
    void insertEnd(Node *nod)
    {
        if (head == nullptr)
        {
            head = nod;
            nod->setNext(nod);
            leng = 1;
        }
        else
        {
            Node *temp = head->Next();
            head->setNext(nod);
            nod->setNext(temp);
            head = nod;
            leng++;
        }
    }
    void insertFront(Node *nod)
    {
        if (head == nullptr)
        {
            head = nod;
            nod->setNext(nod);
            leng++;
        }
        else
        {
            nod->setNext(head->Next());
            head->setNext(nod);
            leng++;
        }
    }
    void insertAt(Node *nod, int loc)
    {
        int n = 0;
        Node *temp = head;

        while (n != loc - 1)
        {
            n++;
            temp = temp->Next();
        }
        Node *temp2 = temp->Next();
        nod->setNext(temp2);
        temp->setNext(nod);
        leng++;
    }
    void deleteEnd()
    {
        Node *temp = head;
        while (temp->Next() != head)
        {
            temp = temp->Next();
        }
        Node *del = temp->Next();
        temp->setNext(head->Next());
        delete del;
        head = temp;
        leng--;
    }

    void deleteFirst()
    {
        Node *fst = head->Next();
        head->setNext(fst->Next());
        delete fst;
        leng--;
    }

    void deleteAt(int loc)
    {
        Node *ptr = head;
        int n = 0;
        while (n != loc - 1)
        {
            ptr = ptr->Next();
            n++;
        }
        Node* del = ptr->Next();
        ptr->setNext(del->Next());
        if(loc % leng == 0){
            head = ptr;
        }
    }

    void print()
    {
        Node *temp = head->Next();
        while (temp != head)
        {
            cout << "  " << temp->giveData();
            temp = temp->Next();
        }
        cout << "  " << temp->giveData();
    }
};

int main()
{
    Node *list[5];
    int ary[5] = {3, 7, 0, 1, 4};
    for (int i = 0; i < 5; i++)
    {
        list[i] = new Node(ary[i]);
    }
    CircularLinkedList lst;
    for (int i = 0; i < 5; i++)
    {
        lst.insertEnd(list[i]);
    }
    Node n1(999);
    lst.insertAt(&n1, 10);

    lst.print();
    lst.deleteAt(11);
    cout << "\n";
    lst.print();
    cout << "\n"
         << lst.length();
}