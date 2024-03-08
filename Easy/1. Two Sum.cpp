class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, vector<int>> sums;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            sums[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int k = target - nums[i];

            if (sums.find(k) != sums.end())
            {
                if (k == nums[i] && sums[k].size() > 1)
                {
                    result.push_back(sums[k][0]);
                    result.push_back(sums[k][1]);
                    return result;
                }
                else if (k != nums[i])
                {
                    result.push_back(i);
                    result.push_back(sums[k][0]);
                    return result;
                }
            }
        }

        return result;
    }
};