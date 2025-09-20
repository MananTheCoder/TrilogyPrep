#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef unordered_set<int> usi;
typedef pair<int, vvi> pivvi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, umii> umiumii;
typedef unordered_map<int, usi> umiusi;

#define forn(i, n) for (int i = 0; i < n; i++)

vector<int> input_vi()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void print_vi(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
    v[0] = 10;
}

void initialize_adj_list(unordered_map<int, unordered_set<int>> &adjacency_list, int v) // O(v)
{
    for (int i = 0; i < v; i++)
    {
        adjacency_list[i] = unordered_set<int>();
    }
}

umiusi make_adjacency_list_ud_uw(pivvi &graph) // O(V + E)
{
    umiusi adjacency_list;
    initialize_adj_list(adjacency_list, graph.first); // O(v)
    int v = graph.first;
    vvi edges = graph.second;
    for (vector<int> &edge : graph.second) // O(E)
    {
        int start = edge[0], end = edge[1];
        // unordered_set<int> &current_set = adjacency_list[start];
        // current_set.insert(end);
        adjacency_list[start].insert(end);
        adjacency_list[end].insert(start);
    }
    return adjacency_list;
}

pivvi dummy_graph()
{
    int v = 7;
    vvi edges({{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {0, 0}});
    vvi edges_weighted({{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 5, 4}, {2, 6, 5}, {3, 6, 6}, {4, 5, 7}});
    pair<int, vector<vector<int>>> graph1 = {v, edges};
    pair<int, vector<vector<int>>> graph_w = {v, edges_weighted};
    return graph1;
}

void dfs_helper(umiusi &adj_list, int curr, vb &visited)
{
    cout << curr << "\t";
    visited[curr] = true;

    // loop over all neighbors
    for (int neighbor : adj_list[curr])
    {
        // check unvisited ones
        if (!visited[neighbor])
        {
            // visit via recursion
            dfs_helper(adj_list, neighbor, visited);
        }
    }
}

void dfs(umiusi &adj_list, int start)
{
    vb visited(adj_list.size(), false);
    dfs_helper(adj_list, start, visited);
    int count = 1;
    forn(i, visited.size())
    {
        if (!visited[i])
        {
            count++;
            dfs_helper(adj_list, i, visited);
        }
    }
    cout << "\n";
}

vvb make_adj_matrix_uw_ud(pivvi &graph)
{
    int v = graph.first;
    vvb adj_matrix(v, vb(v, false));
    vvi edges = graph.second;
    for (vector<int> &edge : edges)
    {
        int start = edge[0], end = edge[1];
        adj_matrix[start][end] = true;
        adj_matrix[end][start] = true;
    }
    return adj_matrix;
}

void dfs_matrix_helper(vvb &adj_matrix, int curr, vb &visited)
{
    cout << curr << "\t";
    visited[curr] = true;

    // for (int neighbor : adj_list[curr])
    forn(i, adj_matrix.size())
    {
        if (adj_matrix[curr][i] && !visited[i])
        {
            dfs_matrix_helper(adj_matrix, i, visited);
        }
    }
}

void dfs_matrix(vvb &adj_matrix, int start)
{
    vb visited(adj_matrix.size(), false);
    dfs_matrix_helper(adj_matrix, start, visited);
    forn(i, adj_matrix.size())
    {
        if (!visited[i])
        {
            dfs_matrix_helper(adj_matrix, i, visited);
        }
    }
}

void playing_with_graphs()
{
    pivvi graph1 = dummy_graph();
    // umiusi adj_list = make_adjacency_list_ud_uw(graph1);
    int start;
    cin >> start;

    vvb adj_matrix = make_adj_matrix_uw_ud(graph1);
    dfs_matrix(adj_matrix, start);
    cout << "\n";
}

void solve()
{
    playing_with_graphs();
}

int main()
{
    solve();
}