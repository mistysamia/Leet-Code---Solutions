class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, zero = 0;
        string ans;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                one++;
            else
                zero++;
        }

        while(one>1){
            one--;
            ans+='1';
        }

        while(zero>0){
            zero--;
            ans+='0';
        }

        ans+='1';

        return ans;
    }
};