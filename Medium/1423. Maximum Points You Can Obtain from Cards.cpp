
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        deque<int> deqFront, deqBack;
        int sumFront = 0, sumBack = 0, ans = -10005, n = cardPoints.size() - 1;
        int i = 0, tempK = k;

        while (i <= n && tempK > 0)
        {
            deqFront.push_back(cardPoints[i]);
            sumFront += cardPoints[i++];
            tempK--;
        }

        tempK = k, i = n;
        while (i >= 0 && tempK > 0)
        {
            deqBack.push_back(cardPoints[i]);
            sumBack += cardPoints[i--];
            tempK--;
        }
        
        int sz = k-1;
        for (int i = 0; i < deqFront.size(); i++)
        {
            ans = max(ans, sumFront);
            sumFront -= deqFront[sz];
            sumFront += deqBack[i];

            ans = max(ans, sumBack);
            sumBack -= deqBack[sz--];
            sumBack += deqFront[i];
        }

        return ans;
    }
};