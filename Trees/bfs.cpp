#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)

void print_vi(vi &v)
{
    for (int &x : v)
    {
        cout << x << "\t";
    }
    cout << "\n";
}

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
    root->right->right->left = new Node(9);
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

void level_wise_alternating_traversal(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> nodes_queue;
    nodes_queue.push(root);
    bool print_straight = true;
    while (!nodes_queue.empty())
    {
        int n = nodes_queue.size();
        vi v(n);
        forn(i, n)
        {
            Node *curr = nodes_queue.front();
            v[i] = curr->data;
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
        if (!print_straight)
        {
            reverse(v.begin(), v.end());
        }
        print_vi(v);
        print_straight = !print_straight;
    }
}

void solve()
{
    Node *root = dummy_tree();
    level_wise_alternating_traversal(root);
}

int main()
{
    solve();
}