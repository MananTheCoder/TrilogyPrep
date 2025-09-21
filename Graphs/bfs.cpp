#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umivi;
typedef pair<int, int> pii;
typedef pair<int, vi> pivi;
typedef pair<int, vvi> pivvi;
typedef pair<int, umii> piumii;
typedef vector<pair<int, int>> vpii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;
const long long INF = 1e18;

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void print_vi(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void print_mivi(umivi &m)
{
    for (pivi one_row : m)
    {
        cout << one_row.first << ": ";
        print_vi(one_row.second);
    }
}

pivvi dummy_graph()
{
    int v = 7;
    vvi edges_uw_ud = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {7, 7}};
    vvi edges_w_d = {{1, 4, 8}, {2, 1, 10}, {2, 6, 7}, {3, 1, 7}, {4, 5, 69}, {5, 2, 8}, {6, 3, 1}, {7, 7, 1}};
    pair<int, vvi> graph_uw_ud = {v, edges_uw_ud}, graph_w_d = {v, edges_w_d};
    return graph_uw_ud;
}

pivvi dummy_graph2()
{
    int v = 7;
    vvi edges_uw_ud = {{1, 4}, {2, 5}, {3, 6}};
    vvi edges_w_d = {{1, 4, 8}, {2, 1, 10}, {2, 6, 7}, {3, 1, 7}, {4, 5, 69}, {5, 2, 8}, {6, 3, 1}, {7, 7, 1}};
    pair<int, vvi> graph_uw_ud = {v, edges_uw_ud}, graph_w_d = {v, edges_w_d};
    return graph_uw_ud;
}

umivi get_adj_list_ud_uw(pivvi &graph)
{
    vvi edges = graph.second;
    // int v = graph.first;
    umivi adj_list;
    forn(i, graph.first)
    {
        adj_list[i + 1] = vi();
    }
    for (vi edge : edges)
    {
        int start_vertex = edge[0];
        int end_vertex = edge[1];

        adj_list[start_vertex].push_back(end_vertex);
        if (start_vertex != end_vertex)
        {
            adj_list[end_vertex].push_back(start_vertex);
        }
    }
    return adj_list;
}

void sanitize_mivi(umivi &m)
{
    for (pair<const int, vi> &one_row : m)
    {
        // one_row.first += 1;
        // cout << typeid(one_row).name() << "\n";
        sort(one_row.second.begin(), one_row.second.end());
    }
}

void bfs_helper(int start_vertex, umivi &adj_list, vb &visited)
{
    queue<int> nodes_queue;
    nodes_queue.push(start_vertex);
    visited[start_vertex] = true;
    while (!nodes_queue.empty())
    {
        int current = nodes_queue.front();
        nodes_queue.pop();
        cout << current << " ";
        for (int neighbor : adj_list[current])
        {
            if (!visited[neighbor])
            {
                nodes_queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void print_bfs(umivi &adj_list, int start_vertex)
{
    vb visited(adj_list.size(), false);
    bfs_helper(start_vertex, adj_list, visited);

    forn(i, visited.size())
    {
        if (!visited[i + 1])
        {
            bfs_helper(i + 1, adj_list, visited);
        }
    }
    cout << "\n";
}

void solve()
{
    pivvi graph = dummy_graph();
    int start_vertex;
    cin >> start_vertex;
    umivi adj_list = get_adj_list_ud_uw(graph);
    sanitize_mivi(adj_list);
    print_bfs(adj_list, start_vertex);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}