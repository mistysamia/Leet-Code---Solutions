class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int freq = 0, ans = 0;

        for(int i=0; i<nums.size();i++)
        {
            mp[nums[i]]++;
            freq = max(freq, mp[nums[i]]);
        }

        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second == freq)
                ans+= freq;
        }

        return ans;
    }
};