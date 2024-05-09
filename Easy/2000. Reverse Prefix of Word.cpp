string reversePrefix(string word, char ch)
{
    string ans = "", temp = "";
    bool checked = false;

    for (int i = 0; i < word.size(); i++)
    {
        if (!checked)
            temp += word[i];
        else
            ans += word[i];

        if (word[i] == ch && !checked)
        {
            checked = true;
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
    }

    if (!checked)
        ans += temp;

    return ans;
}