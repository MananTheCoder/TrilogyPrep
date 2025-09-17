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

void print_inorder(Node *root) // T(n)
{
    if ((!root->left) && (!root->right)) // detecting leaf
    {
        cout << root->data << "\t";
        return;
    }
    print_inorder(root->left);  // T(n/2)
    cout << root->data << "\t"; // 1
    print_inorder(root->right); // T(n/2)
}

void print_preorder(Node *root)
{
    //
}

void print_postorder(Node *root)
{
    //
}

void solve()
{
    Node *root = dummy_tree();
    print_inorder(root);
    cout << "\n";
}

int main()
{
    solve();
}