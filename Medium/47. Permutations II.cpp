class Solution {
public:
    map<vector<int>, int> mp;
    void perm(vector<int> &nums, int indx, vector<vector<int>> &ans)
    {
        if (nums.size() == indx)
        {
            mp[nums]++;
            if (mp[nums] == 1)
                ans.push_back(nums);
            return;
        }

        for (int i = indx; i < nums.size(); i++)
        {
            swap(nums[i], nums[indx]);
            perm(nums, indx + 1, ans);
            swap(nums[i], nums[indx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        perm(nums, 0, ans);
        return ans;
    }
};