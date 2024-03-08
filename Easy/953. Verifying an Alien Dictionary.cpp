class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        map<char, int> mp;
        map<int, char> mpChr;

        char ch = 'a';
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
            mpChr[i] = ch;
            ch++;
        }

        int len = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                words[i][j] = mpChr[mp[words[i][j]]];
            }
        }
        
        return is_sorted(words.begin(),words.end());
    }
};