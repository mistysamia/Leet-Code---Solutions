class Solution {
public:
    bool isHappy(int n)
    {
        map<int, int> mp;
        string s = to_string(n);

        while (1)
        {
            int sum = 0;
            for (int i = 0; i < s.size(); i++)
                sum += pow(s[i] - '0', 2);

            mp[sum]++;

            if (mp[sum] > 1)
                return false;

            s = to_string(sum);
            if (sum == 1)
                return true;
        }

        return false;
    }
};