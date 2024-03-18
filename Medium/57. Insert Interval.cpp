vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    vector<int> temp, vec;

    int last = newInterval[1], first = newInterval[0];

    for (int i = 0; i < intervals.size(); i++)
    {
        temp = intervals[i];
        if (temp[1] < newInterval[0] || temp[0] > newInterval[1])
        {
            if (temp[0] > newInterval[1] && last != -1)
            {
                vec.push_back(first);
                vec.push_back(last);
                last = -1;
                ans.push_back(vec);
                vec.clear();
            }
            vec.push_back(temp[0]);
            vec.push_back(temp[1]);
            ans.push_back(vec);
            vec.clear();
        }
        else
        {
            first = min(first, temp[0]);
            last = max(last, temp[1]);
        }
    }

    if (last != -1)
    {
        vec.push_back(first);
        vec.push_back(last);
        ans.push_back(vec);
    }

    return ans;
}