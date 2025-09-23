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

int fib(int n)
{
    // return (n < 2) ? n : fib(n - 1) + fib(n - 2);
    if (n < 2)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib_memo(int n, vi &memo)
{
    // cout << n << "\n";
    // if (n < 2)
    // {
    //     return n;
    // }

    if (memo[n] != -1)
    {
        return memo[n];
    }
    // memo[n] = fib(n - 1) + fib(n - 2);
    // return memo[n];
    return (memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo));
}

int fib_memo_cleaner(int n, vi &memo)
{
    // top down approach
    return (memo[n] != -1) ? memo[n] : (memo[n] = fib_memo_cleaner(n - 1, memo) + fib_memo_cleaner(n - 2, memo));
}

int fib_tabulation(int n)
{
    // bottom up approach
    // if (n < 0)
    // {
    //     return -1;
    // }

    vi dp(n + 1, -1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib_space_optimisation(int n)
{
    // dimensionality reduction
    int prev = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve()
{
    int n;
    cin >> n;
    vi memo(n + 1, -1); // show that we can run by initializing with 0 also.
    memo[0] = 0, memo[1] = 1;
    // cout << fib_memo(n, memo) << "\n";
    cout << fib_space_optimisation(n) << '\n';
}

int main()
{
    solve();
}