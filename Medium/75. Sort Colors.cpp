class Solution {
public:
    void sortColors(vector<int> &nums)
    {
        int arr[4];
        arr[1] = arr[2] = arr[0] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }

        int j = 0;
        for (int i = 0; i < 3; i++)
        {
            int k = arr[i];
            while (k--)
            {
                nums[j++] = i;
            }
        }
    }
};