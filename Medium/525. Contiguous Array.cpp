int findMaxLength(vector<int> &nums)
{
    map<int, int> mp;
    int mx = 0, diff = 0;
    mp[0] = -1;

    for (int i = 0; i < nums.size(); ++i)
    {
        diff += nums[i] == 0 ? -1 : 1;
        if (mp.find(diff) != mp.end())
            mx = max(mx, i - mp[diff]);
        else
            mp[diff] = i;
        cout << mx << " " << i << endl;
    }

    return mx;
}