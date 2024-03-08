class Solution {
public:
    string removeKdigits(string num, int k)
    {
        deque<char> deq;
        string ans = "";
        int i = 0;

        while (i < num.length())
        {
            while (!deq.empty() && deq.back() > num[i] && k > 0)
            {
                deq.pop_back();
                k--;
            }
            deq.push_back(num[i++]);
        }

        while (!deq.empty() && k > 0)
            deq.pop_back(), k--;

        while (!deq.empty() && deq.front() == '0')
            deq.pop_front();

        while (!deq.empty())
        {
            ans += deq.front();
            deq.pop_front();
        }

        return ans.empty() ? "0" : ans;
    }
};