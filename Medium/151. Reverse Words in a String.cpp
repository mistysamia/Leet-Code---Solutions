class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";
        deque<string>deq;

        for(int i = 0; i<s.size() ; i++)
        {
            if(s[i]==' ' && !word.empty())
            {
                deq.push_front(word);
                word.clear();
            }
            while(i<s.size() && s[i]==' ')
                i++;
            
            if(i<s.size())
                word+=s[i];
        }
        
        if(!word.empty())
            deq.push_front(word);

        while(!deq.empty())
        {
            ans+= deq.size() > 1 ? deq.front()+ ' ' : deq.front();
            deq.pop_front();
        }

        return ans;
    }
};