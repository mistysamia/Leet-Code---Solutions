#include <bits/stdc++.h>
using namespace std;

int dp[100];
int steps(int n, int i)
{
    if (i > n)
        return 0;

    if (i == n)
        return 1;

    if (dp[i] != -1)
        return dp[i];

    dp[i] = steps(n, i + 1) + steps(n, i + 2);
    return dp[i];
}

int climbStairs(int n)
{
    memset(dp, -1, sizeof dp);
    return steps(n, 0);
}

int main()
{

    int t = 100;

    while (t--)
    {
        int n, target, k, m;
        vector<int> nums, tums, ans;
        vector<string> str;
        vector<vector<int>> matrix, mat;
        string s, s1;
        cin >> n;

        cout << climbStairs(n) << endl;
    }
}

//Comment from Feature-1