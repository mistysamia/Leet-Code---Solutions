int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    deque<int> deq;
    int indx = 0, cnt = 0, prod = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        deq.push_back(nums[i]);
        prod *= nums[i];

        while (prod >= k && !deq.empty())
        {
            prod /= deq.front();
            deq.pop_front();
        }

        cnt += deq.size();
    }

    return cnt;
}