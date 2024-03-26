vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;

    for (auto num : nums)
    {
        cout << num << " " << abs(num) << " " << abs(num) - 1 << " " << nums[abs(num) - 1] << " ";
        if (nums[abs(num) - 1] < 0)
        { // seen before
            ans.push_back(abs(num));
        }

        nums[abs(num) - 1] *= -1;
        cout << nums[abs(num) - 1] << endl;
    }

    return ans;
}