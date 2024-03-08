class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
   
        int j=0;

        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[j-1]<nums[i]){
                nums[j++]=nums[i];
            }
        }

        return j;
    }
};