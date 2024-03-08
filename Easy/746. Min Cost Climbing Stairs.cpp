class Solution {
public:
    int dp[1008];

    int minClimb(int indx, vector<int> &cost)
    {
        if (cost.size() <= indx)
            return 0;

        if (dp[indx] != -1)
            return dp[indx];

        int a = 10000, b = 10000;

        a = cost[indx] + minClimb(indx + 1, cost);
        b = cost[indx] + minClimb(indx + 2, cost);

        dp[indx] = min(a, b);
        return dp[indx];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof dp);
        return min(minClimb(0, cost),minClimb(1, cost));
    }
};