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

int factorial(int n)
{
    // return (n < 0) ? -1 : (n < 2) ? 1
    //   : n * factorial(n - 1);
    if (n < 0)
    {
        return -1;
    }
    if (n < 2)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void solve()
{
    int n;
    cin >> n;
    cout << factorial(n) << "\n";
}

int main()
{
    solve();
}