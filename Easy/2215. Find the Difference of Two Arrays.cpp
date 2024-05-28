class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2;
        vector<vector<int>>vec;
        vec.resize(2);

        for(int i = 0; i<nums1.size(); i++)
            mp1[nums1[i]]++;
        
        for(int i = 0; i<nums2.size(); i++)
            mp2[nums2[i]]++;

        for(auto it = mp1.begin(); it != mp1.end(); it++)
        {
            if(mp2.find(it->first) == mp2.end())
                vec[0].push_back(it->first);
        }

        for(auto it = mp2.begin(); it != mp2.end(); it++)
        {
            if(mp1.find(it->first) == mp1.end())
                vec[1].push_back(it->first);
        }

        return vec;
    }
};