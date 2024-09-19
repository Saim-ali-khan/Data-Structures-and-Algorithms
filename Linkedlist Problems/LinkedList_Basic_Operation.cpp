#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int ndata)
    {
        this->data = ndata;
        this->next = nullptr;
    }
    int giveData()
    {
        return data;
    }

    void setNext(Node *nxt)
    {
        next = nxt;
    }
    Node **giveNext()
    {
        return (&next);
    }
};

class LinkedList
{
private:
    Node *head;
    Node **last;

public:
    LinkedList(Node *fst)
    {
        head = fst;
        last = (*(fst)).giveNext();
    }
    Node *giveHead()
    {
        return head;
    }

    int length()
    {
        int l = 0;
        Node *ptr = head;
        while (ptr != nullptr)
        {
            l++;
            ptr = *((*(ptr)).giveNext());
        }
        return l;
    }

    int searchNode(int f)
    {
        int point = 0;

        Node *ptr = head;

        while (ptr != nullptr)
        {
            point++;
            if (((ptr)->giveData()) == f)
            {
                return point;
            }
            else
            {
                ptr = *((*ptr).giveNext());
            }
        }
        return -1;
    }

    void addNode(Node *nwnode)
    {
        *last = nwnode;
        last = (*(nwnode)).giveNext();
        (*(nwnode)).setNext(nullptr);
    }

    void addNodeFirst(Node *addN)
    {
        (*(addN)).setNext(head);
        head = addN;
    }

    void addNodeLast(Node *addN)
    {
        Node *ptr = head;
        int k = 1, i = 1;
        while (ptr != nullptr)
        {
            k++;
            ptr = *((*(ptr)).giveNext());
        }

        ptr = head;
        while (i < k - 1)
        {
            ptr = *((*(ptr)).giveNext());
            i++;
        }
        (*ptr).setNext(addN);
    }
    void addNodeAt(Node *addN, int loc)
    {
        Node *ptr = head;
        int i = 1;

        while (i < loc - 1)
        {
            ptr = *((*ptr).giveNext());
            i++;
        }
        (*addN).setNext(*((*ptr).giveNext()));
        ptr->setNext(addN);
    }

    void deleteFirstNode()
    {
        head = *((*head).giveNext());
    }

    void deleteNodeLast()
    {
        Node *ptr = head;

        int i = this->length();
        for (int j = 1; j < i - 1; j++)
        {
            ptr = *((*ptr).giveNext());
        }
        (*ptr).setNext(nullptr);
    }
    void deleteNodeAt(int loc)
    {
        Node *ptr = head;
        if (loc == 1)
        {
            head = *(ptr->giveNext());
        }
        else
        {
            for (int j = 1; j < (loc - 1); j++)
            {
                ptr = *(ptr->giveNext());
            }

            Node *thrd = *((*(ptr->giveNext()))->giveNext());
            (*ptr).setNext(thrd);
        }
    }

    void MiddleNodes()
    {
        int l = this->length();
        Node *ptr = head;
        int mid;
        if (l % 2 != 0)
        {
            mid = (l / 2) + 1;
            for (int i = 1; i <= mid - 1; i++)
            {
                ptr = *(ptr->giveNext());
            }
            cout << "Middle Node Data : " << ptr->giveData();
        }
        else
        {
            mid = l / 2;
            for (int i = 1; i <= mid - 1; i++)
            {
                ptr = *(ptr->giveNext());
            }
            cout << "Middle Node Data : " << ptr->giveData() << "  " << (*(ptr->giveNext()))->giveData();
        }
    }

    int nthData(int loc)
    {
        Node *ptr = head;
        for (int i = 1; i <= loc - 1; i++)
        {
            ptr = *(ptr->giveNext());
        }
        return ptr->giveData();
    }

    int nthLastData(int loc)
    {
        Node *ptr = head;
        int l = this->length();
        for (int i = 1; i <= l - loc; i++)
        {
            ptr = *(ptr->giveNext());
        }
        return ptr->giveData();
    }

    void MoveLtoF()
    {
        Node *ptr = head;
        int l = this->length();

        for (int i = 1; i < l - 1; i++)
        {
            ptr = *(ptr->giveNext());
        }
        (*(ptr->giveNext()))->setNext(head);
        head = *(ptr->giveNext());
        ptr->setNext(nullptr);
    }

    int sumNnodes(int n)
    {
        Node *ptr = head;
        int l = this->length();
        int sum = 0;
        for (int i = 0; i <= l - n - 1; i++)
        {
            ptr = *(ptr->giveNext());
        }
        while (ptr != nullptr)
        {
            sum += ptr->giveData();
            ptr = *(ptr->giveNext());
        }
        return sum;
    }

    void Swap()
    {
        int l = this->length();
        Node* ptr = head;

        for(int i=1; i<l-2;i++){
            if(i/2 != 0)
            {
                Node* temp = *(ptr->giveNext());
                
            }
            else{
                ptr=*(ptr->giveNext());
            }
        }
    }
    void Reverse(){
        Node* ptr = head;

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = *(head->giveNext());

        while(curr != nullptr){

            next = *(curr->giveNext());


            curr->setNext(prev);
            
            prev = curr;    
            curr = next;
            cout<<"R";
        }
        head = prev;
    }
    void RemoveDuplicates(){
        // data must be sorted
        Node* ptr = head;
        int l = this->length();

        Node* next = *(ptr->giveNext());
        for(int i=1 ; i<(l-1);i++){
            
            next = *(ptr->giveNext());

            if((ptr->giveData()) == (next->giveData())){
                this->deleteNodeAt(i+1);
                i--;
            }
            else{
                ptr = *(ptr->giveNext());
            }
        }
    }
    void printList()
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            cout << (*(ptr)).giveData() << "  ";
            ptr = *((*(ptr)).giveNext());
        }
    }
};

int main()
{
    cout << "Add New Node:- \n";
    Node ary[4] = {31,31,39, 66};
    Node node1(999);
    Node node2(4);
    LinkedList head(&node1);
    for (int i = 0; i < 4; i++)
    {
        head.addNodeLast(&ary[i]);
    }

    // head.printList();
    head.printList();
    head.RemoveDuplicates();
    cout<<"\n";
    head.printList();
}