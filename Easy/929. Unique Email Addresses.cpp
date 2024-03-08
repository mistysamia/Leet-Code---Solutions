class Solution {
public:
    int numUniqueEmails(vector<string> &emails)
    {
        map<string, int> mp;
        
        for (int i = 0; i < emails.size(); i++)
        {
            string s;
            bool at = false, plus = false;
            for (int j = 0; j < emails[i].size(); j++)
            {
                
                if (emails[i][j] == '+' && !at)
                {
                    plus = true;
                }
                else if (emails[i][j] == '@')
                {
                    plus = false;
                    at= true;
                }

                if (!plus)
                {
                    if(emails[i][j] == '.' && !at){
                        continue;
                    }
                    s += emails[i][j];
                }
            }
            mp[s]++;
        }

        return mp.size();
    }
};