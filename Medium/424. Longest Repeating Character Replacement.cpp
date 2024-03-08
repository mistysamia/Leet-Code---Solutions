class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int ch[30];

        memset(ch, 0, sizeof ch);
        int mx = 1, len = 0;

        int val = s[0] - 65;
        ch[val]++;
        len++;
        for (int i = 1; i < s.size(); i++)
        {
            val = s[i] - 65;
            ch[val]++;
            len++;
            bool check = false;
            for (int j = 0; j < 26; j++)
            {
                if (ch[j] >= max((len - k), 0))
                {
                    check = true;
                    break;
                }
            }

            if (check)
            {
                mx = max(mx, len);
            }
            else
            {
                val = s[i - (len - 1)] - 65;
                ch[val]--;
                len--;
            }
        }

        return max(mx, len);
    }
};