class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int mx = 0, n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        map<char, int> mp;
        n = 0;
        for (int j = i; j < s.length(); j++)
        {
            if (mp[s[j]] == 0)
            {
                mp[s[j]]++;
                n++;
            }
            else
            {
                mx = max(mx, n);
                n = 0;
                break;
            }
        }
        mx = max(mx, n);
    }

    return mx;
    }
};