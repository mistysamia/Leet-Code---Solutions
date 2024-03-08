class Solution {
public:
    int strStr(string haystack, string needle) {
         int i = 0;
    int n = haystack.length();
    int m = needle.length();

    while (i + m <= n)
    {
        string s = haystack.substr(i, m);
        //cout << i << " " << s << endl;
        if (s == needle)
        {
            return i;
        }
        i++;
    }
    return -1;
    }
};