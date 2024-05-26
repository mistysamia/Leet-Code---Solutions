void backtrack(string s , unordered_set<string>& wordSet , int indx , vector<string>& vec, string temp, string ans)
{
    if(indx > s.size())
        return;
    
    if(wordSet.find(temp) != wordSet.end())
    {
        string tempAns = ans == "" ? temp : ans+" "+temp;
        if(indx < s.size())
        {
            std::string tempStr(1, s[indx]);
            backtrack(s, wordSet, indx+1, vec, tempStr , tempAns);
        }
        else
        {
            vec.push_back(tempAns);
            return;
        }
    }    
    temp+=s[indx];
    backtrack(s, wordSet, indx+1, vec, temp, ans);
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> vec;
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    
    backtrack(s , wordSet , 0 , vec, "", "");
    return vec;
    
}