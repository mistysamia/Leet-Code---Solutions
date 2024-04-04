int maxSubarrayLength(vector<int> &nums, int k)
{
    int mx = INT_MIN, len = 0, indx = 0;
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        len++;

        while (mp[nums[i]] > k)
        {
            mp[nums[indx++]]--;
            len--;
        }

        mx = max(mx, len);
    }

    return mx;
}