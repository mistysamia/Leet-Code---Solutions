class Solution {
public:
    int minimumLength(string s) {
        int n = s.size()-1 , i=0;

        int ans =0;

        while( i < n)
        {
            char a = s[i];
            char b = s[n];

            if(a != b)
                break;

            while(i<n && s[i] == b )
            {
                i++;
                ans++; 
            }
            while( i<=n && s[n] == a )
            {
                n--;
                ans++; 
            }
        }
        
        return s.size() - ans;
    }
};