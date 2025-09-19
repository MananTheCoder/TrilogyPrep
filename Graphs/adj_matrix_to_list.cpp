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

pivvi dummy_graph()
{
    int v = 7;
    vvi edges({{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}});
    vvi edges_weighted({{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 5, 4}, {2, 6, 5}, {3, 6, 6}, {4, 5, 7}});
    pair<int, vector<vector<int>>> graph1 = {v, edges};
    pair<int, vector<vector<int>>> graph_w = {v, edges_weighted};
    return graph_w;
}

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

void print_adj_matrix_uw(vvb &adj_matrix)
{
    for (vb &row : adj_matrix)
    {
        for (bool val : row)
        {
            cout << val << "\t";
        }
        cout << "\n";
    }
}

void fill_adj_matrix_uw_ud(pivvi &graph, vvb &adj_matrix)
{
    int v = graph.first;
    vector<vector<int>> edges = graph.second;
    for (vector<int> &edge : edges)
    {
        int start = edge[0], end = edge[1];
        adj_matrix[start][end] = true;
        adj_matrix[end][start] = true;
    }
}

void fill_adj_matrix_uw_d(pivvi &graph, vvb &adj_matrix)
{
    int v = graph.first;
    vector<vector<int>> edges = graph.second;
    for (vector<int> &edge : edges)
    {
        int start = edge[0], end = edge[1];
        adj_matrix[start][end] = true;
    }
}

vector<vector<int>> make_adj_matrix_ud_w(pair<int, vector<vector<int>>> &graph_w)
{
    int v = graph_w.first;
    vector<vector<int>> adj_matrix(v, vector<int>(v, -1));
    for (vector<int> &edge : graph_w.second)
    {
        int start = edge[0], end = edge[1];
        adj_matrix[start][end] = edge[2];
        adj_matrix[end][start] = edge[2];
    }
    return adj_matrix;
}

vector<vector<int>> make_adj_matrix_d_w(pair<int, vector<vector<int>>> &graph_w)
{
    int v = graph_w.first;
    vector<vector<int>> adj_matrix(v, vector<int>(v, -1));
    for (vector<int> &edge : graph_w.second)
    {
        // int start = edge[0], end = edge[1];
        adj_matrix[edge[0]][edge[1]] = edge[2];
    }
}

umiumii convert_adj_matrix_to_list_w_d(vector<vector<int>> &adj_matrix_w_d)
{
    //
}

void playing_with_graphs()
{
    // pair<int, vector<vector<int>>> graph1 = dummy_graph();
    // int v = graph1.first;
    // vvb adj_matrix_uw_ud(v, vector<bool>(v, false));
    // fill_adj_matrix_uw_ud(graph1, adj_matrix);
    // umiusi adj_list = convert_adj_matrix_to_list_uw_ud(adj_matrix_uw_ud);

    pair<int, vector<vector<int>>> graph_w = dummy_graph();
    vector<vector<int>> adj_matrix_w_d = make_adj_matrix_d_w(graph_w);
    umiumii adj_list_w_d = convert_adj_matrix_to_list_w_d(adj_matrix_w_d);
}

void solve()
{
    playing_with_graphs();
}

int main()
{
    solve();
}