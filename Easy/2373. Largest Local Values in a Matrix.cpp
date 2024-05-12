  vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
  {
    vector<vector<int>> vec;
        vec.resize(grid.size() - 2);

    for (int i = 0; i < grid.size() - 2; i++) 
    {
        for (int j = 0; j < grid[0].size() - 2; j++) 
        {
            int maxVal = INT_MIN;

            for (int row = i; row < i + 3; row++) 
                for (int col = j; col < j + 3; col++) 
                    maxVal = max(maxVal, grid[row][col]);

            vec[i].push_back(maxVal);
        }
    }

    return vec;
}