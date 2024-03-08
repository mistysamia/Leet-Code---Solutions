class Solution
{
#define pii pair<pair<pair<string, string>, string>, string>
#define ff first
#define ss second
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {

        vector<string> ans;
        deque<pii> deq;
        for (int i = 0; i < transactions.size(); i++)
        {
            int comma = 1;
            string s1, s2, s3, s4;
            for (int j = 0; j < transactions[i].size(); j++)
            {
                if (transactions[i][j] == ',')
                    comma++, j++;

                if (comma == 1)
                    s1 += transactions[i][j];

                if (comma == 2)
                    s2 += transactions[i][j];

                if (comma == 3)
                    s3 += transactions[i][j];

                if (comma == 4)
                    s4 += transactions[i][j];
            }
            deq.push_back({{{s1, s2}, s3}, s4});
        }

        map<int, int> mp;
        for (int i = 0; i < transactions.size(); i++)
        {
            pii x = deq[i];
            if (stoi(x.ff.ss) > 1000)
            {
                if (mp.find(i) == mp.end())
                {
                    ans.push_back(transactions[i]);
                    mp[i]++;
                }
            }

            for (int j = i + 1; j < transactions.size(); j++)
            {
                pii y = deq[j];
                if (x.ff.ff.ff == y.ff.ff.ff && abs(stoi(x.ff.ff.ss) - stoi(y.ff.ff.ss)) <= 60 &&
                    x.ss != y.ss)
                {
                    if (mp.find(i) == mp.end())
                    {
                        ans.push_back(transactions[i]);
                        mp[i]++;
                    }
                    if (mp.find(j) == mp.end())
                    {
                        ans.push_back(transactions[j]);
                        mp[j]++;
                    }
                }
            }
        }

        return ans;
    }
};