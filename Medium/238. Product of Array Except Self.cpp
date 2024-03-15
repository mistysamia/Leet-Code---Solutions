vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero = 0;

        for(int i = 0; i <nums.size();i++)
        {
            if(nums[i] != 0)
                product*=nums[i];
            else
                zero++;
        }

        for(int i = 0; i <nums.size();i++)
        {
            if(zero == 1 && nums[i] == 0 )
                nums[i] = product;
            else if(zero > 0)
                nums[i] = 0;
            else
                nums[i] = product / nums[i];
        }

        return nums;
    }