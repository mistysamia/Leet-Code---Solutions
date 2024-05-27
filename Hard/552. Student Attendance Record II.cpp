class Solution {
public:
    int dp[100001][2][3];
    int mod = 1e9 + 7;

    int attendanceCombination(int n, int indx , int absent, int consLate) 
    {
        if(indx > n)
            return 0;
        if(indx == n)
            return 1;

        if(dp[indx][absent][consLate] != -1)
            return dp[indx][absent][consLate];
        
        int a = 0, b = 0, c = 0;
        a = attendanceCombination(n, indx+1 , absent, 0 ) % mod; 
        if(absent < 1)
            b =  attendanceCombination(n, indx+1 , absent + 1, 0 ) % mod; 
        if(consLate < 2)    
            c =  attendanceCombination(n, indx+1 , absent, consLate + 1 ) % mod; 
        
        long sum = ( (a + b) % mod + c ) % mod;
        return dp[indx][absent][consLate] = sum;
    }

    int checkRecord(int n) {
        memset(dp, -1 , sizeof dp);
        int ans = attendanceCombination(n, 0 , 0, 0 );
        return ans;
    }
};