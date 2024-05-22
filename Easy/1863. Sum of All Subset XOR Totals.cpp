int sum = 0;
void backtrack (vector<int>& nums, vector<int>& temp, int indx)
{
    int tempSum = 0;
    for(int i = 0; i<temp.size(); i++)
    {
        if(i == 0)
            tempSum = temp[i];
        else
            tempSum^=temp[i];
    }
    sum+= tempSum;

    for(int i = indx ; i<nums.size() ; i++)
    {
        temp.push_back(nums[i]);
        backtrack(nums, temp, i+1);
        temp.pop_back();
    }
}

int subsetXORSum(vector<int>& nums) {
    vector<int>temp;
    sum = 0;
    backtrack (nums, temp, 0);
    return sum;
}