#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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

int helper(vi &v, int i)
{
    if (i == v.size())
    {
        return 0;
    }
    return v[i] + helper(v, i + 1);
}

int helper(int i, vi &v)
{
    if (i < 0)
    {
        return 0;
    }
    return v[i] + helper(i - 1, v);
}

int vector_sum(vi &v)
{
    return helper(v.size() - 1, v);
}

void solve()
{
    vi v = input_vi();
    cout << vector_sum(v) << "\n";
}

int main()
{
    solve();
}