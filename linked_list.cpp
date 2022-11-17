#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    friend class linkedlist;
    node()
    {
        data = 0;
        next = nullptr;
    }
    node(int k)
    {
        data = k;
        next = nullptr;
    }
};

class linkedlist
{
    node *head;

public:
    linkedlist()
    {
        head = nullptr;
    }

    void createlist(int);
    void insertnodes(int, int);
    void deletenode(int);
    void printlist();
};

void linkedlist::createlist(int n)
{
    node *temp = head;
    cout << "Enter elements\n";
    while (n--)
    {
        int k;
        cin >> k;
        node *n = new node(k);
        if (head == nullptr)
        {
            temp = head = n;
        }
        else
        {
            temp->next = n;
            temp = n;
        }
    }
}

void linkedlist::insertnodes(int k, int pos)
{
    if (pos < 1)
    {
        cout << "Wrong input\n";
        return;
    }
    node *n = new node(k);
    if (pos == 1)
    {
        n->next = head;
        head = n;
        return;
    }
    node *temp = head;
    while (pos-- > 2)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Wrong input\n";
        return;
    }
    n->next = temp->next;
    temp->next = n;
}

void linkedlist::deletenode(int k)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    node *temp = head, *back = nullptr;
    if (head->data == k)
    {
        head = head->next;
        delete (temp);
        return;
    }
    while (temp != nullptr && temp->data != k)
    {
        back = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
        return;
    back->next = temp->next;
    delete (temp);
}

void linkedlist::printlist()
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    cout << "Linked list is\n";
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    linkedlist l1;
    int n;
    cout << "Enter total number of elements in linked list-> ";
    cin >> n;
    l1.createlist(n);
    l1.printlist();
    int pos;
    cout << "Enter data to be inserted and its pos-> ";
    cin >> n >> pos;
    l1.insertnodes(n, pos);
    l1.printlist();
    cout << "Enter the data of element to be deleted-> ";
    cin >> n;
    l1.deletenode(n);
    l1.printlist();
    return 0;
}
