class Solution {
public:
    string createLow(int m, int n, int limit)
    {
        string ans;
        while (n < limit)
        {
            ans += to_string(m);
            m++, n++;
        }
        return ans;
    }

    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        string s = to_string(low), start = "0", end;
        int startVal = s[0] - '0', n = s.size();

        while (stoll(start) < low)
        {
            if (startVal + n > 10)
            {
                n++;
                startVal = 1;
            }

            start = createLow(startVal, 0, n);
            startVal++;
        }
        
        if(stoll(start) <= high)
            ans.push_back(stoll(start));

        startVal = (start[0] - '0') + 1;
        n = start.size();

        while (1)
        {
            if (startVal + n > 10)
            {
                n++;
                startVal = 1;
            }

            start = createLow(startVal, 0, n);
            startVal++;

            if (stoll(start) <= high)
                ans.push_back(stoll(start));
            else
                break;
        }

        return ans;
    }
};