int findDuplicate(vector<int> &nums)
{
    vector<int> vec(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        vec[nums[i]]++;
        if (vec[nums[i]] > 1)
            return nums[i];
    }

    return -1;
}