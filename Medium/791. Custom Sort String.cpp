class Solution {
public:
    string customSortString(string order, string s)
    {
        int indx = 0;
        map<char,int>mp;

        for (int i = 0; i < s.size(); i++) 
            mp[s[i]]++;

        string ans;
        for(int i = 0; i<order.size() ;i++)
        {
            while(mp[order[i]]>0)
            {
                ans+=order[i];
                mp[order[i]]--;
            }
        }

        for(auto it = mp.begin(); it!=mp.end() ;it++)
        {
            while(it->second>0)
            {
                ans+=it->first;
                it->second--;
            }
        }
        return ans;
    }
};