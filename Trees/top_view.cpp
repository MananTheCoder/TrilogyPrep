#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
// typedef pair<Node *, int> pNi;
typedef unordered_map<int, int> umii;

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
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->left->left = new Node(9);
    return root;
}

void print_top_nodes(umii &top_nodes, int min_dist, int max_dist)
{
    for (int i = min_dist; i <= max_dist; i++)
    {
        cout << top_nodes[i] << "\t";
    }
    cout << "\n";
}

void print_top_view(Node *root)
{
    if (!root)
    {
        return;
    }
    umii top_nodes;
    int min_dist = INT_MAX, max_dist = INT_MIN;
    queue<pair<Node *, int>> nodes_queue;
    nodes_queue.push({root, 0});
    while (!nodes_queue.empty())
    {
        Node *curr = nodes_queue.front().first;
        int dist = nodes_queue.front().second;
        min_dist = min(min_dist, dist);
        max_dist = max(max_dist, dist);
        if (top_nodes[dist] == 0)
        {
            top_nodes[dist] = curr->data;
        }

        if (curr->left)
        {
            nodes_queue.push({curr->left, dist - 1});
        }
        if (curr->right)
        {
            nodes_queue.push({curr->right, dist + 1});
        }

        nodes_queue.pop();
    }

    print_top_nodes(top_nodes, min_dist, max_dist);
}

void solve()
{
    Node *root = dummy_tree();
    print_top_view(root);
}

int main()
{
    solve();
}