class Solution {
    #define ll long long
public:
    int addDigits(int num) {
auto s = std::to_string(num);


    ll sum = 0, temp = 0;
    map<ll, ll> mp;
    while (1)
    {
        sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int n = s[i] - '0';
            sum += n;
        }
        if (s.size()==1)
            break;

        s = std::to_string(sum);
    }

    return sum;
    }
};