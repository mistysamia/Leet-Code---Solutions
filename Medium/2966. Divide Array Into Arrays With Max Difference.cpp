class Solution {
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        vector<vector<int>> ans;
        if (nums.size() % 3 != 0)
            return ans;

        sort(nums.begin(), nums.end());

        int mn = nums[0], indx = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt < 3)
            {
                if(nums[i] - mn <= k)
                {
                    cnt++;
                    ans[indx].push_back(nums[i]);
                }
                else{
                    ans.clear();
                    return ans;
                }
            }

            if (cnt == 3)
            {
                indx++;
                cnt = 0;
                mn = i + 1 < nums.size() ? nums[i + 1] : -1;
            }
        
        }

        return ans;
    }
};