#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forLL(temp, head) for (Node *temp = head; temp != nullptr; temp = temp->next)

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }
    LinkedList(Node *head)
    {
        this->head = head;
    }

    void insertNodeTail(int data); // 4
    void deleteNode(int pos);      // 5
    void print_list();             // 1
    int size();                    // 2
    bool search(int val);          // 3
};

void LinkedList::print_list()
{
    // Node *temp = head;
    // while (temp != nullptr)
    // {
    // cout << temp->data << "\t";
    // temp = temp->next;
    // }
    // cout << "\n";

    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        cout << temp->data << "\t";
    }
    cout << "\n";
}

int LinkedList::size()
{
    int count = 0;
    forLL(temp, head)
    {
        count++;
    }
    return count;
}

bool LinkedList::search(int val)
{
    forLL(temp, head)
    {
        if (temp->data == val)
        {
            return true;
        }
    }
    return false;
}

void LinkedList::insertNodeTail(int data)
{
    // LL is empty
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        //
    }
    temp->next = new Node(data);
}

void LinkedList::deleteNode(int pos)
{
    if (!head)
    {
        cout << "LL is empty.\n";
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int _size = size();
    if (pos > _size)
    {
        cout << "Pos > size of LL.\n";
        return;
    }

    Node *prev;
    for (prev = head; pos > 2; prev = prev->next, pos--)
    {
        // code should break at prev
    }
    // cout << prev->data << "\n";
    Node *temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
}

void playing_with_LL()
{
    LinkedList list1(new Node(1));
    forn(i, 4)
    {
        list1.insertNodeTail(i + 2);
    }
    // list1.print_list();
    cout << list1.search(2) << "\n";
    list1.deleteNode(2);
    cout << list1.search(2) << "\n";
    // list1.print_list();
}

void solve()
{
    playing_with_LL();
}

int main()
{
    solve();
}