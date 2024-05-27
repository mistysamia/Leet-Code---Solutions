class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        map<int,int>mp;
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> vec;

        for(int i = 0; i<candies.size() ; i++)
        {
            if(candies[i] + extraCandies >= mx)
                vec.push_back(true);
            else
                vec.push_back(false);
        }

        return vec;
    }
};