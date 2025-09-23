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

// vector<int> input_vi()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     return v;
// }

void print_dists(vi &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << i << ":\t" << v[i] << "\n";
    }
    cout << "\n";
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

pair<int, vector<vector<int>>> dummy_graph()
{
    // int v = 7;
    vvi edges({{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}});
    // vvi edges_weighted({{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 5, 4}, {2, 6, 5}, {3, 6, 6}, {4, 5, 7}});
    int v = 5;
    vvi edges_weighted = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    pair<int, vector<vector<int>>> graph1 = {v, edges};
    pair<int, vector<vector<int>>> graph_w = {v, edges_weighted};
    return graph_w;
}

int find_shortest_dist_vertex(vi &min_dists, vb &finalised)
{
    int short_dist_vertex = -1, min_dist = INT_MAX;
    forn(i, min_dists.size())
    {
        if (min_dists[i] < min_dist && !finalised[i])
        {
            min_dist = min_dists[i];
            short_dist_vertex = i;
        }
    }
    return short_dist_vertex;
}

void dijkstra(umiumii &adj_list, int src)
{
    int n = adj_list.size();
    vb finalised(n, false);
    vi min_dists(n, INT_MAX);
    min_dists[src] = 0;

    forn(i, n)
    {
        // find the non finalised vertex with min_dist
        int closest_vertex = find_shortest_dist_vertex(min_dists, finalised);
        finalised[closest_vertex] = true;

        // update weights of all neighbors
        for (pair<const int, int> &row : adj_list[closest_vertex])
        {
            int neighbor = row.first, weight = row.second;
            if (min_dists[closest_vertex] + weight < min_dists[neighbor] && !finalised[neighbor])
            {
                min_dists[neighbor] = min_dists[closest_vertex] + weight;
            }
        }
    }

    print_dists(min_dists);
}

void playing_with_graphs()
{
    pivvi graph_w = dummy_graph();
    umiumii adj_list = make_adj_list_w_ud(graph_w);
    int src;
    cin >> src;
    dijkstra(adj_list, src);
}

void solve()
{
    playing_with_graphs();
}

int main()
{
    solve();
}