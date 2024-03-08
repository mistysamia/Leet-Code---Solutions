class Solution {
public:
int dp[100005];
int maxProfit(vector<int> &prices)
{
    int mx = 0;
    int price = 100000;
    int ans = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        mx = max(mx,prices[i]-price);
        price = min(price,prices[i]);
    }
    return mx;
}
};