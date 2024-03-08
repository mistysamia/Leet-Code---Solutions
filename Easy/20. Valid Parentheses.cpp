class Solution
{
public:
    bool isValid(string s)
    {
        deque<char> deq;
        bool check = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                deq.push_back(s[i]);
            }

            if (s[i] == ')')
            {
                if (deq.size() > 0 && deq.back() == '(')
                    deq.pop_back();
                else
                {
                    check = false;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                if (deq.size() > 0 && deq.back() == '{')
                    deq.pop_back();
                else
                {
                    check = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (deq.size() > 0 && deq.back() == '[')
                    deq.pop_back();
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if (deq.size() != 0)
        {
            check = false;
        }
        return check;
    }
};