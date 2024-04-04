bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    map<char, char> mp, tp;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) == mp.end())
            mp[s[i]] = t[i];
        else if (mp[s[i]] != t[i])
            return false;

        if (tp.find(t[i]) == tp.end())
            tp[t[i]] = s[i];
        else if (tp[t[i]] != s[i])
            return false;
    }

    return true;
}