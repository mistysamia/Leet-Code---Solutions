class Solution {
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }

        deque<char> deq;
        for (int i = 0; i < goal.size(); i++)
        {
            deq.push_back(goal[i]);
        }

        int i = 0;
        while (i < goal.size())
        {
            if (s[0] == deq.front())
            {
                bool check = true;
                for (int j = 0; j < s.size(); j++)
                {
                    if (s[j] != deq[j])
                    {
                        check = false;
                        break;
                    }
                }
                cout << endl;
                if (check)
                {
                    return true;
                }
            }

            char temp = deq.front();
            deq.push_back(temp);
            deq.pop_front();
            i++;
        }
        return false;
    }
};