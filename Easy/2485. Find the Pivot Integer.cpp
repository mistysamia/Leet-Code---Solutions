class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        while(n)
        {
            sum+=n;
            int temp = (n * (n+1))/2; 
            if(sum == temp)
                return n;
           
            n--;
        }      
        return -1;  
    }
};