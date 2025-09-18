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

void make_adj_matrix(pivvi &graph)
{
    //
}

void make_adj_list(pivvi &graph)
{
    //
}

void convert_to_adj_list(vvb &adj_matrix)
{
    //
}

void convert_to_adj_matrix(umiusi &adj_list)
{
    //
}

void convert_to_adj_matrix(umiumii &adj_list)
{
    //
}

pivvi dummy_graph()
{
    int v = 7;
    vvi edges({{1, 2}, {1, 3}, {1, 4}, {2, 5}});
    return {v, edges};
}

void solve()
{
    pivvi graph1 = dummy_graph();
}

int main()
{
    solve();
}