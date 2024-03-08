class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        deque<int> deq;
        int arr[10008];

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            if (deq.empty())
            {
                arr[nums2[i]] = -1;
            }
            else
            {
                while (!deq.empty() && deq.back() < nums2[i])
                {
                    deq.pop_back();
                }
                if (!deq.empty() && deq.back() > nums2[i])
                {
                    arr[nums2[i]] = deq.back();
                }
                else
                {
                    arr[nums2[i]] = -1;
                }
            }
            deq.push_back(nums2[i]);
        }

        for (auto it : nums1)
        {
            ans.push_back(arr[it]);
        }

        return ans;
    }

};