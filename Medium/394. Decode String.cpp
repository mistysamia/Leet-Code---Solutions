class Solution
{
public:
    string decodeString(string s)
    {
        string s1, num;
        deque<string> deq;
        int m;
        int len = s.length();

        int i = len - 1;
        while (i >= 0)
        {
            if (s[i] == '[')
            {

                i--;
                num.clear();
                while (i >= 0 && s[i] >= '0' && s[i] <= '9')
                {
                    num += s[i--];
                }
                reverse(num.begin(), num.end());
                m = stoi(num);
                s1.clear();
                while (!deq.empty())
                {
                    if (deq.front() == "]")
                    {
                        deq.pop_front();
                        break;
                    }
                    s1 += deq.front();
                    deq.pop_front();
                }
                string temp;
                for (int i = 0; i < m; i++)
                {
                    temp += s1;
                }
                deq.push_front(temp);
            }
            else
            {
                string temp;
                temp += s[i--];
                deq.push_front(temp);
            }
        }
        string final;
        for (int i = 0; i < deq.size(); i++)
        {
            final += deq[i];
        }

        return final;
    }
};