class Solution {
public:
    int minJumps(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        if (index == n - 1) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int minJumpsRequired = 100000;
        int maxJump = min(nums[index], n - 1 - index);

        for (int j = 1; j <= maxJump; ++j) {
            int nextIndex = index + j;
            int jumpsToNext = minJumps(nums, nextIndex, dp);
            minJumpsRequired = min(minJumpsRequired, jumpsToNext + 1);
        }
        dp[index] = minJumpsRequired;
        return minJumpsRequired;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return minJumps(nums, 0, dp);
    }

};