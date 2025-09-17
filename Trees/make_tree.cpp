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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void solve()
{
    //
}

int main()
{
    solve();
}