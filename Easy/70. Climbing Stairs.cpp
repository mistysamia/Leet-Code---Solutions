class Solution {
public:
    int dp[50];
    int climb(int n, int count)
    {
        if (n < count)
        {
            return 0;
        }
        if (n == count)
        {
            return 1;
        }

        if (dp[count] != 0)
            return dp[count];

        dp[count] = climb(n, count + 1) + climb(n, count + 2);
        return dp[count];
    }

    int climbStairs(int n)
    {
        memset(dp, 0, sizeof(dp));
        return climb(n, 0);
    }
};