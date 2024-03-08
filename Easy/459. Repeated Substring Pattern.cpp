class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int len;
        for (int i = 0; i < s.size() / 2; i++)
        {
            len = i + 1;
            string s1 = s.substr(0, len);
            
            int j = len;
            bool repeat = true;
            while (j < s.size())
            {
                string s2 = s.substr(j, len);
                if (s1 != s2)
                {
                    repeat = false;
                    break;
                }
                j += len;
            }

            if (repeat)
                return true;
        }

        return false;
    }
};