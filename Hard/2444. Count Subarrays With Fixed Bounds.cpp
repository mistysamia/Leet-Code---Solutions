long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    long long cnt = 0, mn = -1, mx = -1, outRange = -1;

    for (long long i = 0; i < nums.size(); i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
            outRange = i;

        if (nums[i] == minK)
            mn = i;

        if (nums[i] == maxK)
            mx = i;

        cnt += max((long long)0, min(mn, mx) - outRange);
    }

    return cnt;
}