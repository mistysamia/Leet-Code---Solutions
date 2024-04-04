long long countSubarrays(vector<int> &nums, int k)
{
    int mxElement = *max_element(nums.begin(), nums.end());
    long long ans = 0;
    int cnt = 0, j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i];
        while (j < nums.size() && cnt < k)
            cnt += nums[j++] == mxElement ? 1 : 0;

        if (cnt < k)
            break;

        ans += nums.size() - j + 1;
        cnt -= temp == mxElement ? 1 : 0;
    }

    return ans;
}