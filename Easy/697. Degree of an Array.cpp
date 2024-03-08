class Solution {
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int mx = -1;
        map<int, pair<int, pair<int, int>>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = make_pair(1, make_pair(i, i));
            }
            else
            {
                auto it = mp[nums[i]];
                mp[nums[i]] = make_pair(it.first + 1, make_pair(it.second.first, i));
            }

            auto itt = mp[nums[i]];
            mx = max(mx, itt.first);
        }

        int duration = 50000;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second.first == mx){
                int temp = it->second.second.second - it->second.second.first;
                duration = min(temp+1,duration);
            }
        }

        return duration;
    }
};