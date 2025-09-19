#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> usi;
typedef pair<int, vvi> pivvi;
typedef unordered_map<int, int> umii;
typedef pair<int, int> pii;
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

void print_neighbors(set<int> &neighbors)
{
    set<int>::iterator itr;
    // (*itr++)
    for (itr = neighbors.begin(); itr != neighbors.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << "\n";
}

void print_adjacency_list(unordered_map<int, set<int>> &adjacency_list)
{
    for (pair<const int, set<int>> &row : adjacency_list)
    {
        int start = row.first;
        set<int> neighbors = row.second;
        cout << start << " : ";
        print_neighbors(neighbors);
    }
}

void print_adj_list_w_ud(umiumii &adj_list)
{
    for (pair<const int, umii> &row : adj_list)
    {
        cout << row.first << " :\n";
        for (pii src_dist : row.second)
        {
            cout << "\t" << src_dist.first << " -> " << src_dist.second << "\n";
        }
        cout << "\n";
    }
}

pair<int, vector<vector<int>>> dummy_graph()
{
    int v = 7;
    vvi edges({{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {0, 0}});
    vvi edges_weighted({{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 5, 4}, {2, 6, 5}, {3, 6, 6}, {4, 5, 7}});
    pair<int, vector<vector<int>>> graph1 = {v, edges};
    pair<int, vector<vector<int>>> graph_w = {v, edges_weighted};
    return graph_w;
}

void initialize_adj_list(unordered_map<int, set<int>> &adjacency_list, int v) // O(v)
{
    for (int i = 0; i < v; i++)
    {
        adjacency_list[i] = set<int>();
    }
}

void fill_adjacency_list_ud_uw(unordered_map<int, set<int>> &adjacency_list, pair<int, vector<vector<int>>> &graph) // O(V + E)
{
    // handle self loop
    // print in ascending order using unordered_map
    initialize_adj_list(adjacency_list, graph.first); // O(v)
    int v = graph.first;
    vvi edges = graph.second;
    for (vector<int> &edge : graph.second) // O(E)
    {
        int start = edge[0], end = edge[1];
        // set<int> &current_set = adjacency_list[start];
        // current_set.insert(end);
        adjacency_list[start].insert(end);
        adjacency_list[end].insert(start);
    }
}

void fill_adjacency_list_d_uw(unordered_map<int, set<int>> &adjacency_list, pair<int, vector<vector<int>>> &graph) // O(V + E)
{
    // handle self loop
    // print in ascending order using unordered_map
    initialize_adj_list(adjacency_list, graph.first); // O(v)
    int v = graph.first;
    vvi edges = graph.second;
    for (vector<int> &edge : graph.second) // O(E)
    {
        int start = edge[0], end = edge[1];
        // set<int> &current_set = adjacency_list[start];
        // current_set.insert(end);
        adjacency_list[start].insert(end);
        // adjacency_list[end].insert(start);
    }
}

void initialize_adj_list(umiumii &adj_list, int v)
{
    forn(i, v)
    {
        adj_list[i] = umii();
    }
}

umiumii make_adj_list_w_ud(pivvi &graph_w)
{
    umiumii adj_list;
    vvi edges_w = graph_w.second;
    int v = graph_w.first;
    initialize_adj_list(adj_list, v);

    for (vi &edge : edges_w)
    {
        adj_list[edge[0]][edge[1]] = edge[2];
        adj_list[edge[1]][edge[0]] = edge[2];
    }
    return adj_list;
}

umiumii make_adj_list_w_d(pivvi &graph_w)
{
    umiumii adj_list;
    initialize_adj_list(adj_list, graph_w.first);

    for (vi &edge : graph_w.second)
    {
        adj_list[edge[0]][edge[1]] = edge[2];
    }
    return adj_list;
}

void playing_with_graphs()
{
    // pair<int, vector<vector<int>>> graph1 = dummy_graph();
    // unordered_map<int, set<int>> adjacency_list;
    // fill_adjacency_list_ud_uw(adjacency_list, graph1);
    // print_adjacency_list(adjacency_list);

    pair<int, vector<vector<int>>> graph_w = dummy_graph();
    umiumii bapu_weighted = make_adj_list_w_d(graph_w);
    print_adj_list_w_ud(bapu_weighted);
}

void solve()
{
    playing_with_graphs();
}

int main()
{
    solve();
}