class Solution {
public:
vector<int> countBits(int n)
{
    int count = 1, i = 0, track = 1, last = 1;
    vector<int> ans;

    ans.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(ans[i / 2] + i % 2);
    }

    return ans;
}
};