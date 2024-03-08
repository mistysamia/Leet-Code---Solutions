class Solution {
public:
    
    struct Compare
    {
        bool operator()(const pair<char, int> &a, const pair<char, int> &b)
        {
            if (a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };

    int leastInterval(vector<char> &tasks, int n)
    {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> maxHeap;
        deque<pair<char, int>> save;
        map<char, int> mp;
        deque<char> deq;

        for (int i = 0; i < tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            maxHeap.push(make_pair(it->first, it->second));
        }

        while (!maxHeap.empty())
        {
            pair<char, int> val = maxHeap.top();
            deq.push_back(val.first);
            save.push_back(val);
            maxHeap.pop();
            int i = n;

            while (i--)
            {
                if (!maxHeap.empty())
                {
                    val = maxHeap.top();
                    deq.push_back(val.first);
                    save.push_back(val);
                    maxHeap.pop();
                }
                else
                {
                    deq.push_back('*');
                }
            }
            while (!save.empty())
            {
                val = save.front();
                save.pop_front();
                if (val.second - 1 > 0)
                    maxHeap.push(make_pair(val.first, val.second - 1));
            }
        }

        while (!deq.empty())
        {
            if (deq.back() == '*')
            {
                deq.pop_back();
            }
            else
            {
                break;
            }
        }

        return deq.size();
    }
};