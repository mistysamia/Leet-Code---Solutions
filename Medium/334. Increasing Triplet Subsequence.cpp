class Solution {
public:
    #define BIG 1e13
    bool increasingTriplet(vector<int> &nums)
    {
        long long int minSec = BIG , minFir = BIG , minThrd = BIG;

        for (int i = 0; i < nums.size(); i++)
        {
            if(minFir>nums[i]){
                minFir = nums[i];
            }else if(minFir<nums[i] && minSec>nums[i]){
                minSec = nums[i];
            }else if(minSec<nums[i] && minThrd>nums[i]){
                minThrd = nums[i];
            }

            if(minSec>minFir && minThrd>minSec && minThrd!=BIG){
                return true;
            }
        }

        return false;
    }
};