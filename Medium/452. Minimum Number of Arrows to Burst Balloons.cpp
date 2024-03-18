#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 1e5
#define pie 3.14159265358979323
#define minuss 1e-6
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define BIG 1e13
#define N 10000
#define MOD 1000000007

char grid[150][157];
ll row[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll col[] = {1, -1, 0, 0, 1, -1, 1, -1};

int findMinArrowShots(vector<vector<int>> &points)
{
    vector<int> vec;
    sort(points.begin(), points.end());
    vec.push_back(1);
    int y = points[0][1], ans = 1;

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= y)
        {
            vec.push_back(vec[i - 1] + 1);
            y = min(y, points[i][1]);
        }
        else
        {
            vec.push_back(1);
            y = points[i][1];
            ans++;
        }
    }

    return ans;
}

int main()
{

    int t = 100;

    while (t--)
    {
        int n, target, k, m;
        vector<int> nums, tums, ans;
        vector<string> s;
        vector<vector<int>> matrix, mat;
        string s1, s2;
        // cin >> s1 >> s2;
        // cout << isSubsequence(s1, s2) << endl;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> k >> m;
            matrix.push_back({k, m});
        }

        cout << findMinArrowShots(matrix) << endl;
    }
}