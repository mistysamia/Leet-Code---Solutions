int lengthOfLastWord(string s)
{
    bool space = true;
    int len = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && !space)
            return len;
        else if (s[i] != ' ')
        {
            space = false;
            len++;
        }
    }

    return len;
}