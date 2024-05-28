class Solution {
public:
    int compress(vector<char>& chars) {
        deque<char>chDeq;
        deque<int>deq;

        for(int i = 0; i < chars.size();i++)
        {
            if(!chDeq.empty() && chDeq.back() == chars[i])
            {
                int val = deq.back();
                deq.pop_back();
                val++;
                deq.push_back(val);
            }
            else
            {
                chDeq.push_back(chars[i]);
                deq.push_back(1);
            }
        }

        string s = "";
        while(!deq.empty())
        {
            cout<<chDeq.front()<<" "<<deq.front()<<endl;
            s+=chDeq.front();
            chDeq.pop_front();
            if(deq.front() != 1)
                s+= to_string(deq.front());
            deq.pop_front();
        }
        
        chars.clear();
        for(int i = 0; i < s.size();i++)
            chars.push_back(s[i]);

        return s.size();
    }
};