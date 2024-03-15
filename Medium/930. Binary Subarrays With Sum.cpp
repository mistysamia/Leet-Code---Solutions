int numSubarraysWithSum(vector<int> &nums, int goal)
{
    map<int, int> mp;
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == goal)
            ans++;
        cout << sum << "  " << ans << "  " << mp[sum - goal] << endl;
        if (mp.find(sum - goal) != mp.end())
            ans += mp[sum - goal];

        mp[sum]++;
    }
    return ans;
}