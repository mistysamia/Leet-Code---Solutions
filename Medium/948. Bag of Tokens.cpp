
class Solution {
public:

    int bagOfTokensScore(vector<int>& tokens, int power) {
        deque<int>deq;

        int score = 0, ans = 0;

        for(int i=0; i < tokens.size(); i++)
            deq.push_back(tokens[i]);
        
        sort(deq.begin(),deq.end());

        while(!deq.empty())
        {
            if(deq.front() <= power)
            {
                power-=deq.front();
                score++;
                deq.pop_front();
            }
            else if(score >= 1)
            {
                power+=deq.back();
                score--;
                deq.pop_back();
            }
            else
                break;
            
            ans = max(score, ans);
        }

        return ans;
    }
};