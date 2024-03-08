class Solution {
public:
    deque<char> insertCharacter(string s)
    {
        deque<char> deq;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                if (!deq.empty())
                {
                    deq.pop_back();
                }
            }
            else
            {
                deq.push_back(s[i]);
            }
        }
        return deq;
    }

    bool backspaceCompare(string s, string t)
    {
        deque<char> s1, s2;

        s1 = insertCharacter(s);
        s2 = insertCharacter(t);

        if (s1.size() != s2.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] != s2[i])
                    return false;
            }
        }
        return true;
    }
};