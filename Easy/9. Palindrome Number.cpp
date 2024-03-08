class Solution {
public:

    bool isPalindrome(int x) {
    int t, i,n;
    string str;
    n = x;

    str = to_string(n);
    
    bool check = true;

    t = str.length() - 1;

    for (; i < str.length() / 2; i++, t--)
    {
        if (str[i] != str[t])
        {
            check = false;
        }
    }

    return check;
    }
};