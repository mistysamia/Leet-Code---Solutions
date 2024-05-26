class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0 , j = 0;
        string mergeString = "";

        while(i<word1.size() && j<word2.size())
        {
            mergeString+=word1[i++];
            mergeString+=word2[j++];
        }

        while(i < word1.size())
            mergeString+=word1[i++];

        while(j < word2.size())
            mergeString+=word2[j++];

        return mergeString;
    }
};