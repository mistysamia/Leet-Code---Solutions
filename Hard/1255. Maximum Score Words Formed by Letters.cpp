class Solution {
public:
    int calculateWordScore(string word, vector<int>& score) {
        int ans = 0;

        for (int i = 0; i < word.size(); i++) 
            ans += score[word[i] - 'a'];
        
        return ans;
    }

    bool canFormWord(string word,  map<char, int>& letterCount) {
        map<char, int> tempCount = letterCount;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (tempCount[ch] <= 0)
                return false;
            
            tempCount[ch]--;
        }
        return true;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char, int> letterCnt;
        for (int i = 0; i < letters.size(); i++) 
            letterCnt[letters[i]]++;
        
        vector<int> wordScores(words.size());
        for (int i = 0; i < words.size(); i++) 
            wordScores[i] = calculateWordScore(words[i], score);
        
        int mx = 0;
        int total = 1 << words.size(); 

        for (int i = 0; i < total; i++) 
        {
            map<char, int> mp = letterCnt;
            int current = 0;
            bool valid = true;
            
            for (int j = 0; j < words.size(); j++) 
            {
                if (i & (1 << j)) 
                {
                    if (canFormWord(words[j], mp)) 
                    {
                        for (int k = 0; k < words[j].size(); k++) 
                            mp[words[j][k]]--;
                        
                        current += wordScores[j];
                    } 
                    else 
                    {
                        valid = false;
                        break;
                    }
                }
            }
            
            if (valid) 
                mx = max(mx, current);
        }

        return mx;
    }
};