class Solution {
public:
    void backtrack(string digits, int indx, vector<string>& ans, string s, vector<string>& characters)
    {
        if(indx >= digits.size())
        {
            if(s.size() > 0)
                ans.push_back(s);
            return;
        }
        
        for(int i = 0; i < characters[digits[indx]-'0'].size(); i++)
            backtrack(digits, indx+1, ans , s + characters[digits[indx]-'0'][i], characters);
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> characters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(digits, 0, ans , "", characters);
        return ans;
    }
};