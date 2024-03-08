class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            if (mp[i] > 1 || mp[i] == 0)
            {
                ans.push_back(i);
            }
        }

        bool check = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ans[0])
            {
                check = true;
                break;
            }
        }

        if (!check)
        {
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};