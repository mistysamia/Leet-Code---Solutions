int maxDepth(string s)
{
    deque<char> deq;
    int mx = INT_MIN;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            deq.push_back('(');
        else if (s[i] == ')' && !deq.empty())
            deq.pop_back();

        mx = max(mx, (int)deq.size());
    }

    return mx;
}