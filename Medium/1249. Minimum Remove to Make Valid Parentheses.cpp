string minRemoveToMakeValid(string s)
{
    deque<char> ans;
    int open = 0;
    string str;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            ans.push_front(s[i]);
        else
        {
            if (s[i] == ')' && open > 0)
            {
                ans.push_front(s[i]);
                open--;
            }
            else if (s[i] == '(')
            {
                ans.push_front(s[i]);
                open++;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == '(')
        {
            if (open > 0)
            {
                open--;
                continue;
            }
            else
                str += ans[i];
        }
        else
            str += ans[i];
    }
    reverse(str.begin(), str.end());

    return str;
}