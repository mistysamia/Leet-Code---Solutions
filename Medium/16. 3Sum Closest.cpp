class Solution {
public:
    int difference(int a, int t)
    {
        if (a < 0 && t >= 0)
            return t - a;
        else if (a >= 0 && t < 0)
            return a - t;
        else
            return abs(t - a);
    }

    int threeSumClosest(vector<int> &nums, int target)
    {
        int mn = 1009, sum = 0, ans = 0, check = -1;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {

                for (int k = j + 1; k < nums.size(); k++)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    if (check == -1)
                    {
                        mn = difference(sum, target);
                        ans = sum;
                        check = 0;
                    }
                    else
                    {
                        ans = difference(sum, target) < mn ? sum : ans;
                        mn = min(difference(sum, target), mn);
                    }
                }
            }

        }

        return ans;
    }
};