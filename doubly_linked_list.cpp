#include <iostream>
using namespace std;

class node
{
    int data;
    node *forw, *prev;

public:
    friend class doublylinkedlist;
    node()
    {
        data = 0;
        forw = prev = nullptr;
    }
    node(int k)
    {
        data = k;
        forw = prev = nullptr;
    }
};

class doublylinkedlist
{
    node *head, *tail;

public:
    doublylinkedlist()
    {
        head = tail = nullptr;
    }

    void createlist(int);
    void insertnodes(int, int);
    void deletenode(int);
    void printlist();
};

void doublylinkedlist::createlist(int t)
{
    cout << "Enter the elements\n";
    while (t--)
    {
        int k;
        cin >> k;
        node *n = new node(k);
        if (head == nullptr)
        {
            head = tail = n;
        }
        else
        {
            tail->forw = n;
            n->prev = tail;
            tail = n;
        }
    }
}

void doublylinkedlist::insertnodes(int k, int pos)
{
    node *n = new node(k);
    if (pos == 1)
    {
        n->forw = head;
        head->prev = n;
        head = n;
        return;
    }
    node *temp = head;
    while (pos-- > 2)
    {
        temp = temp->forw;
    }
    if (temp == nullptr || pos < 1)
    {
        cout << "wrong input" << endl;
    }
    n->forw = temp->forw;
    n->prev = temp;
    temp->forw = n;
}

void doublylinkedlist::deletenode(int k)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->data == k)
    {
        head = head->forw;
        delete (head->prev);
        return;
    }
    node *up = head, *dow = nullptr;
    while (up != nullptr && up->data != k)
    {
        dow = up;
        up = up->forw;
    }
    if (up == nullptr)
        return;
    dow->forw = up->forw;
    if (up->forw != nullptr)
        up->forw->prev = dow;
    else
        tail = dow;
    delete (up);
}

void doublylinkedlist::printlist()
{
    node *temp = head;
    cout << "Linked list is\n";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->forw;
    }
    cout << endl;
}

int main()
{
    doublylinkedlist l1;
    int t;
    cout << "Enter total no. of elements in linked list-> ";
    cin >> t;
    l1.createlist(t);
    l1.printlist();
    int pos;
    cout << "Enter element to be inserted and its position-> ";
    cin >> t >> pos;
    l1.insertnodes(t, pos);
    l1.printlist();
    cout << "Enter data of element to be deleted-> ";
    cin >> t;
    l1.deletenode(t);
    l1.printlist();
    return 0;
}