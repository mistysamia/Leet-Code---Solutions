double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<pair<double, int>> vec;
    priority_queue<int> pq; 
    int amount = 0;
    double minCost = DBL_MAX;

    for (int i = 0; i < quality.size(); i++) 
        vec.push_back({(double)wage[i] / quality[i], quality[i]});

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) 
    {
        amount += vec[i].second; 
        pq.push(vec[i].second); 

        if (pq.size() > K) 
        {
            amount -= pq.top(); 
            pq.pop(); 
        }

        if (pq.size() == K) {
            minCost = min(minCost, amount * vec[i].first);
        }
    }

    return minCost;
}