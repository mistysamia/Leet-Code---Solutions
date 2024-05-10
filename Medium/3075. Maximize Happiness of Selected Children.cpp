    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> pq;

        for(int i = 0; i<happiness.size() ; i++)
            pq.push(happiness[i]);

        long long min = 0, sum = 0;
        while(k--)
        {
            sum+= max(pq.top() - min, (long long)0);
            min++;
            pq.pop();
        }

        return sum;
    }