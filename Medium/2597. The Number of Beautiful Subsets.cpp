bool isBeautiful(vector<int>& temp, int num, int k)
{
    for(int i = 0 ; i<temp.size() ; i++)
    {
        if( abs(temp[i]-num) == k)
            return false;
    }

    return true;
}

void backtrack(vector<int>& nums, int indx , vector<int>&temp,  vector<vector<int>>& vec, int k)
{
    vec.push_back(temp);

    for(int i = indx; i<nums.size(); i++)
    {
        if(isBeautiful(temp , nums[i], k) )
        {
            temp.push_back(nums[i]);
            backtrack(nums, i+1 , temp, vec, k);
            temp.pop_back();
        }
    }
}

int beautifulSubsets(vector<int>& nums, int k) {
    vector<vector<int>> vec;
    vector<int> temp;

    backtrack(nums, 0 , temp, vec, k);
    return vec.size() - 1;
}