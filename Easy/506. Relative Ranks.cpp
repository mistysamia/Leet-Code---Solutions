vector<string> findRelativeRanks(vector<int>& score) {
    vector<string>ans;
    vector<int>vec;
    vec = score;
    sort(vec.begin(), vec.end(), greater<int>());
    map<int,int>mp;
    
    for(int i = 0; i<vec.size(); i++)
        mp[vec[i]] = i+1;
    
    for(int i = 0 ; i<score.size(); i++)
    {
        auto it = mp.find(score[i]);
        
        if( it->second == 1)
            ans.push_back("Gold Medal");
        else if( it->second == 2)
            ans.push_back("Silver Medal");
        else if( it->second == 3)
            ans.push_back("Bronze Medal");
        else
            ans.push_back(to_string(it->second));
    }

    return ans;
}