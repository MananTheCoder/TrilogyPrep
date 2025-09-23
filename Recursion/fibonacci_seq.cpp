#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)

int fib(int n)
{
    // return (n < 2) ? n : fib(n - 1) + fib(n - 2);
    if (n < 2)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

void solve()
{
    int n;
    cin >> n;
    vi memo(n + 1, -1); // show that we can run by initializing with 0 also.
    memo[0] = 0, memo[1] = 1;
    // cout << fib_memo(n, memo) << "\n";
    cout << fib(n) << '\n';
}

int main()
{
    solve();
}