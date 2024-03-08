class Solution {
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        map<int, int> mp;
        int mn = -1, n = wall.size(),ans=-1;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                sum += wall[i][j];
                mp[sum]++;
                mn = max(mn+1, n-mp[sum]+1);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (n - it->second < mn)
            {
                mn = n - it->second;
                ans = mn;
            }
        }

        return ans == -1 ? wall.size() : ans;
    }
};