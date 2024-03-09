#include <bits/stdc++.h>
using namespace std;

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    deque<int> deq1, deq2;

    for (int i = 0; i < nums1.size(); i++)
        deq1.push_back(nums1[i]);

    for (int i = 0; i < nums2.size(); i++)
        deq2.push_back(nums2[i]);

    while (!deq1.empty() && !deq2.empty())
    {
        if (deq1.front() == deq2.front())
            return deq1.front();

        if (deq1.front() < deq2.front())
            deq1.pop_front();
        else
            deq2.pop_front();
    }

    return -1;
}

int main()
{

    int t = 100;

    while (t--)
    {
        int n, target, k, m;
        vector<int> nums, tums, ans;
        vector<string> str;
        vector<vector<int>> matrix, mat;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            nums.push_back(k);
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> k;
            tums.push_back(k);
        }

        cout << getCommon(nums,tums) << endl;
    }
}