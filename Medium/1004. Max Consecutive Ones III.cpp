class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int save[4];
        save[0] = save[1] = 0;
        int count = 0, indx = 0, ans = -1, n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            save[nums[i]]++;
            if (save[0] > k)
            {
                ans = max(ans, i - indx);
                while (save[0] > k)
                {
                    save[nums[indx]]--;
                    indx++;
                }
            }
        }

        return max(ans, n - indx);
    }
};