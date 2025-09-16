#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)

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

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

void creating_node_by_node()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    head->next = second;
    Node *third = new Node(3);
    second->next = third;
    Node *four = new Node(4);
    third->next = four;
}

void using_better_constructor()
{
    Node five(5);
    Node four(4, &five);
    Node three(3, &four);
    Node two(2, &three);
    Node head(1, &two);
    print_list(&head);
}

void loop_and_shift_head()
{
    Node *head = nullptr; // why runtime here
    forn(i, 5)
    {
        head = new Node(i + 11, head);
    }
    print_list(head);
}

void playing_with_nodes()
{
    // creating_node_by_node();
    // using_better_constructor();
    loop_and_shift_head();
}

void solve()
{
    playing_with_nodes();
}

int main()
{
    solve();
}