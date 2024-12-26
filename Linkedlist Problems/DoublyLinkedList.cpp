#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int dat) : data(dat)
    {
        prev = next = nullptr;
    }
    void setNext(Node *add)
    {
        next = add;
    }
    void setPrev(Node *add)
    {
        prev = add;
    }
    Node *Prev()
    {
        return prev;
    }
    Node *Next()
    {
        return next;
    }
    int giveData()
    {
        return data;
    }
};

class DoubleLinkedList
{
private:
    Node *head;

public:
    DoubleLinkedList()
    {
        head = nullptr;
    }
    DoubleLinkedList(Node *node)
    {
        head = node;
    }
    int length()
    {
        Node *ptr = head;
        int l = 0;
        while (ptr != nullptr)
        {
            l++;
            ptr = ptr->Next();
        }
        return l;
    }
    void add(Node *node)
    {
        if (head != nullptr)
        {
            Node *ptr = head;
            int l = this->length();
            for (int i = 1; i < l; i++)
            {
                ptr = ptr->Next();
            }
            ptr->setNext(node);
            node->setPrev(ptr);
            node->setNext(nullptr);
        }
        else
        {
            head = node;
            node->setNext(nullptr);
            node->setPrev(nullptr);
        }
    }
    void addFirst(Node *node)
    {
        node->setNext(head);
        head->setPrev(node);
        node->setPrev(nullptr);
        head = node;
    }

    Node *giveAddress(int loc)
    {
        Node *ptr = head;
        int l = this->length();
        for (int i = 1; i < loc; i++)
        {
            ptr = ptr->Next();
        }
        return ptr;
    }

    void addSpec(Node *node, int loc)
    {

        if (loc == 1)
        {
            this->addFirst(node);
        }
        else
        {
            Node *ptr = this->giveAddress(loc - 1);
            node->setNext(ptr->Next());
            node->setPrev(ptr);
            (ptr->Next())->setPrev(node);
            ptr->setNext(node);
        }
    }
    void deleteFirst()
    {
        Node *ptr = head;
        head = head->Next();
        head->setPrev(nullptr);
        delete ptr;
    }

    void deleteEnd()
    {
        Node *fs, *sc, *th;
        fs = sc = nullptr;
        th = head;
        while (th != nullptr)
        {
            fs = sc;
            sc = th;
            th = th->Next();
        }
        fs->setNext(nullptr);
        delete sc;
    }
    void deleteSpec(int loc)
    {
        if (loc == 1)
        {
            this->deleteFirst();
        }
        else if (loc == this->length())
        {
            this->deleteEnd();
        }
        else
        {
            Node *ptr = this->giveAddress(loc - 1);
            Node *mid = (ptr->Next())->Next();
            mid->setPrev(ptr);
            delete (ptr->Next());
            ptr->setNext(mid);
        }
    }
    void Rotate()
    {
        Node *ptr;
        int l = this->length();
        ptr = this->giveAddress(l);
        (ptr->Prev())->setNext(nullptr);
        ptr->setPrev(nullptr);
        ptr->setNext(head);
        head = ptr;
    }

    void deleteLastOccur(int dat)
    {
        int l = this->length();
        Node *ptr = this->giveAddress(l);
        while (ptr->giveData() != dat && ptr != nullptr)
        {
            ptr = ptr->Prev();
            l--;
        }
        if (ptr != nullptr)
        {
            this->deleteSpec(l);
        }
        else
        {
            return;
        }
    }
    void deleteAllOccur(int dat)
    {
        Node *ptr = head;
        // used equal ,because if the last one is dat then without equal it will not check data of it
        for (int i = 1; i <= this->length(); i++)
        {
            if (ptr->giveData() == dat)
            {

                ptr = ptr->Next();
                this->deleteSpec(i);
                i--;
            }
            else
            {
                ptr = ptr->Next();
            }
        }
    }
    void Reverse()
    {
        int l = this->length();
        Node *fs = head;
        Node *ls = this->giveAddress(l);
        Node *fir = this->giveAddress(l);
        for (int i = 1; i <= (l / 2); i++)
        {

            Node *temp = ls->Prev();
            Node *temp2 = fs->Next();

            (ls->Prev())->setNext(fs);
            (fs->Next())->setPrev(ls);

            fs->setNext(ls->Next());
            ls->setNext(temp2);

            fs->setPrev(temp);
            ls->setPrev(fs->Prev());

            fs = temp2;
            ls = temp;
        }

        head = fir;
    }
    void print()
    {
        Node *ptr = head;

        cout << "\nData : \n";
        while (ptr != nullptr)
        {
            cout << ptr->giveData() << "  ";
            ptr = ptr->Next();
        }
    }
};

int main()
{
    Node *nodes[6];
    int ary[6] = {45, 1, 26, 4, 5, 2};
    for (int i = 0; i < 6; i++)
    {
        nodes[i] = new Node(ary[i]);
    }

    DoubleLinkedList list;
    for (int i = 0; i < 6; i++)
    {
        list.add(nodes[i]);
    }
    Node node1(33);
    list.print();
    list.Reverse();
    list.print();
}
