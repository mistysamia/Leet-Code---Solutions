vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    double low = 0.0, high = 1.0;
    int p = 0, q = 1;

    while (true) 
    {
        double mid = (low + high) / 2;
        int count = 0;
        p = 0;

        for (int i = 0, j = 0; i < arr.size(); i++) 
        {
            while (j < arr.size() && arr[i] > mid * arr[j]) 
                j++;

            count += arr.size() - j;
            if (j < arr.size() && p * arr[j] < q * arr[i]) 
            {
                p = arr[i];
                q = arr[j];
            }
        }

        if (count == k) 
            return {p, q};
        else if (count < k) 
            low = mid;
        else 
            high = mid;
    }
}