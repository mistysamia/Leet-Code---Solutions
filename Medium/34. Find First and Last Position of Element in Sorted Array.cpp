class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int indx = -1, left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] == target)
            {
                right = mid - 1;
                indx = mid;
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
        ans.push_back(indx);

        indx = -1, left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] == target)
            {
                left = mid + 1;
                indx = mid;
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
        ans.push_back(indx);
        return ans;
    }
};