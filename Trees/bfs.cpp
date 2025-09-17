#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)

struct Node
{
    int data;
    Node *left, *right;
    ;

    Node()
    {
        int data = -1;
        left = right = nullptr;
    }

    Node(int data)
    {
        this->data = data;
    }
};

Node *dummy_tree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    return root;
}

void level_order_traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> nodes_queue;
    nodes_queue.push(root);
    while (!nodes_queue.empty())
    {
        cout << nodes_queue.front()->data << "\t";
        if (nodes_queue.front()->left)
        {
            nodes_queue.push(nodes_queue.front()->left);
        }
        if (nodes_queue.front()->right)
        {
            nodes_queue.push(nodes_queue.front()->right);
        }
        nodes_queue.pop();
    }
    cout << "\n";
}

void level_wise_order_traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> nodes_queue;
    nodes_queue.push(root);
    while (!nodes_queue.empty())
    {
        int n = nodes_queue.size();
        forn(i, n)
        {
            Node *curr = nodes_queue.front();
            cout << curr->data << "\t";
            if (curr->left)
            {
                nodes_queue.push(curr->left);
            }
            if (curr->right)
            {
                nodes_queue.push(curr->right);
            }
            nodes_queue.pop();
        }
        cout << "\n";
    }
}

void solve()
{
    Node *root = dummy_tree();
    level_wise_order_traversal(root);
}

int main()
{
    solve();
}