class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        if (strs.size() == 1)
        {
            return strs[0];
        }
        string s;
        int ans = 10000;
        for (int i = 0; i < strs.size() - 1; i++)
        {
            string s1, s2;
            s1 = strs[i];
            s2 = strs[i + 1];
            int len = 0;
            // cout<<s1<<" "<<s2<<endl;
            if (s1 == s2)
            {
                len = s1.size();
            }
           else
            {
                while (ans > len)
                {
                    if (s1[len] == s2[len])
                        len++;
                    else
                        break;
                }
            }

            ans = min(len, ans);
        }

        for (int i = 0; i < ans; i++)
        {
            s += strs[0][i];
        }

        return s;
    }
};