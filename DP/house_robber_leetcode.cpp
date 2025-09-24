typedef vector<int> vi;

class Solution
{
private:
    int recursive(vi &nums, int i)
    {
        // BC
        if (i == 0)
        {
            return nums[0];
        }
        if (i == 1)
        {
            return max(nums[0], nums[1]);
        }

        // RF
        int take = nums[i] + recursive(nums, i - 2);
        int notTake = recursive(nums, i - 1);
        return max(take, notTake);
    }
    int memo_func(vi &nums, int i, vi &memo)
    {
        if (memo[i] != -1)
        {
            return memo[i];
        } // come back and analyse for 0, -2 (Dibyanshu)
        int take = nums[i] + memo_func(nums, i - 2, memo);
        int notTake = memo_func(nums, i - 1, memo);
        return (memo[i] = max(take, notTake));
    }
    int tabulation(vi &nums)
    {
        int n = nums.size();
        vi dp(n, -1);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            // int take = nums[i] + dp[i-2];
            // int notTake = dp[i-1]
            // dp[i] = max(take, notTake);
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        // vi memo(n, -1);
        int prev2 = nums[0], prev = max(nums[0], nums[1]);
        // return tabulation(nums);
        for (int i = 2; i < n; i++)
        {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};