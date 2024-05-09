bool checkValidString(string s)
{
    deque<char> deq;
    int open = 0, close = 0, star = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == '*')
            star++;
        else
            close++;

        if (close > open + star)
            return false;
    }

    open = 0, close = 0, star = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == '*')
            star++;
        else
            close++;

        if (open > close + star)
            return false;
    }

    return true;
}