int findMaxK(vector<int>& nums) {
        map<int, int>mp;
        int mx = -1;

        for(int i = 0; i<nums.size() ; i++)
            mp[nums[i]]++;

        for(int i = 0; i<nums.size() ; i++)
        {
            if(mp.find(nums[i]) != mp.end() && mp.find(nums[i] * -1) != mp.end())
            {
                if(nums[i]<0)
                    nums[i]*=-1;
                
                if(nums[i] > mx)
                    mx = nums[i];
            }
        }

        return mx;
    }