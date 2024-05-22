void backtrack (vector<int>& nums, vector<int>& temp, int indx, vector<vector<int>>& vec)
{
    vec.push_back(temp);
    for(int i = indx ; i<nums.size() ; i++)
    {
        temp.push_back(nums[i]);
        backtrack(nums, temp, i+1, vec);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vec;
    vector<int> temp;

    backtrack (nums, temp, 0, vec);

    return vec;
}