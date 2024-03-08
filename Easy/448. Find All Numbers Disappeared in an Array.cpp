class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans, vec;
        ans.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(0);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            ans[nums[i]] = 1;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            if (ans[i] == 0)
            {
                vec.push_back(i);
            }
        }
        return vec;
    }
};