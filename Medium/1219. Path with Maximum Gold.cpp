int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
int dfs(vector<vector<int>>& grid, int i, int j) {

    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        return 0;
    
    int gold = grid[i][j];
    grid[i][j] = 0;
    
    int mx = INT_MIN;
    for (int k = 0; k < 4; k++) {
        int row = i + fx[k];
        int col = j + fy[k];
        mx = max(mx, dfs(grid, row, col));
    }
    
    grid[i][j] = gold; 
    return gold + mx;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int cnt = 0;
    
    for (int i = 0; i < grid.size(); i++) 
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] != 0) 
                cnt = max(cnt, dfs(grid, i, j));
    
    return cnt;
}