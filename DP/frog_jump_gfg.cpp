typedef vector<int> vi;

class Solution
{
private:
    int minCost(vi &height, int i)
    { // i ->index
        // Base Case
        if (i < 2)
        {
            return (i == 0) ? 0 : abs(height[1] - height[0]);
        }

        // RF
        int one_gap = abs(height[i] - height[i - 1]) + minCost(height, i - 1);
        int two_gap = abs(height[i] - height[i - 2]) + minCost(height, i - 2);
        return min(one_gap, two_gap);
    }

    int memo_fn(vi &height, int i, vi &memo)
    {
        if (memo[i] != -1)
        {
            return memo[i];
        }
        int one_gap = abs(height[i] - height[i - 1]) + memo_fn(height, i - 1, memo);
        int two_gap = abs(height[i] - height[i - 2]) + memo_fn(height, i - 2, memo);
        return (memo[i] = min(one_gap, two_gap));
    }

    int tabulation(vi &height)
    {
        // every func call must be handled in 1 iteration
        // convert func para -> loop var
        int n = height.size();
        vi dp(n, -1);
        dp[0] = 0, dp[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            int one_gap = abs(height[i] - height[i - 1]) + dp[i - 1];
            int two_gap = abs(height[i] - height[i - 2]) + dp[i - 2];
            dp[i] = min(one_gap, two_gap);
        }
        return dp[n - 1];
    }

public:
    int minCost(vector<int> &h)
    {
        // Code here
        if (h.size() < 2)
        {
            return 0;
        }
        int prev2 = 0, prev = abs(h[1] - h[0]);
        for (int i = 2; i < h.size(); i++)
        {
            int curr = min(abs(h[i] - h[i - 1]) + prev, abs(h[i] - h[i - 2]) + prev2);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};