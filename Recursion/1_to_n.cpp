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

void print_1_to_n(int n)
{
    if (n < 1)
    {
        return;
    }
    print_1_to_n(n - 1);
    cout << n << "\t";
}

void print_1_to_n(int n, int i)
{
    if (n < 1)
    {
        return;
    }
    print_1_to_n(n - 1, i);
    cout << n;
    (i == n) ? cout << "\n" : (cout << "\t");
    // if (i == n)
    // {
    //     cout << "\n";
    // }
}

void print_n_to_1(int n)
{
    if (n == 1)
    {
        cout << n << "\n";
        return;
    }
    cout << n << "\t";
    print_n_to_1(n - 1);
}

void solve()
{
    int n;
    cin >> n;
    int i = n;
    print_1_to_n(n, i);
    // print_n_to_1(n);
    // cout << "\n";
}

int main()
{
    solve();
}