class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, mid, n = nums.size() - 1;
        while (left <= right)
        {
            mid = (right + left) / 2;
            if (nums[mid] <= nums[n])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};