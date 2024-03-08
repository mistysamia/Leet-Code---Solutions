class Solution {
#define ll long long
    #define BIG 1000000000
public:
    int romanToInt(string s) {
        map<char, ll> mp;
    //  map<ll,ll>::iterator it;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    // deque<ll>deq;
    ll lock = 0, sum = 0, co = 0, ans = 0, a = 0, b = 0, c = 0, d = 0;
    ll n, m, k, mx = -BIG, mn = BIG;
    ll fir = 0, sec = 0, x = 0, y = 0, point, in, temp = -BIG;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (temp > mp[s[i]])
            ans -= mp[s[i]];
        else
            ans += mp[s[i]];

        temp = mp[s[i]];
    }

   return ans;
    }
};