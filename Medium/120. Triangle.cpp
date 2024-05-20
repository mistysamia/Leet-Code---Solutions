int mem[201][201];

int dp(vector<vector<int>>& triangle, int i , int j ) {
    if(i >= triangle.size())
        return 0;
    if(j >= triangle[i].size())
        return 0;

    if(mem[i][j] != INT_MAX)
        return mem[i][j];
    
    mem[i][j] =  triangle[i][j] + min(dp(triangle, i+1, j), dp(triangle, i+1 , j+1));
    return mem[i][j];
}

int minimumTotal(vector<vector<int>>& triangle) {
    for(int i = 0; i < 201;i++)
        for( int j = 0; j <201; j++)
            mem[i][j] = INT_MAX;

    
    return dp(triangle, 0 , 0);
}