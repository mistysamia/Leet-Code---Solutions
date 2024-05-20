long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long int res = 0;
    long long int d = INT_MAX;
    long long int c = 0;

    for (int i = 0; i<nums.size() ; i++) 
    {
        long long int a = nums[i];
        long long int b = a ^ k;
        res += max(a, (long long int)b);
        c ^= a < b ? 1 : 0;
        d = min(d, (long long int)abs(a - b));
    }
    return res - d * c;
}