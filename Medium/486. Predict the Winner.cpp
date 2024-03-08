class Solution {
public:
    map<pair<int,int>, int> mp;
    int canWinGameHelper(vector<int> &nums, int indx, int n, int p1Score, int p2Score, bool p1Turn)
    {
        if (indx >= n)
            return p1Score - p2Score;

        if (mp[make_pair(indx,n)] > 0)
            return mp[make_pair(indx,n)];

        int a, b;
        if (p1Turn)
        {
            a = canWinGameHelper(nums, indx + 1, n, p1Score + nums[indx], p2Score, false);
            b = canWinGameHelper(nums, indx, n - 1, p1Score + nums[n], p2Score, false);
            return mp[make_pair(indx,n)] = max(a, b);
        }
        else
        {
            a = canWinGameHelper(nums, indx + 1, n, p1Score, p2Score + nums[indx], true);
            b = canWinGameHelper(nums, indx, n - 1, p1Score, p2Score + nums[n], true);
            return mp[make_pair(indx,n)] = min(a, b);
        }
    }

    bool predictTheWinner(vector<int> &nums)
    {
        return canWinGameHelper(nums, 0, nums.size() - 1, 0, 0, true) >= 0;
    }
};
