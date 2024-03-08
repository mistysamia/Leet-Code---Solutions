class Solution {
public:
int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid = (left + right) / 2;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
};