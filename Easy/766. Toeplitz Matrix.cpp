class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                int col = j + 1;
                int row = i + 1;

                while (row < matrix.size() && col < matrix[row].size())
                {
                    if (matrix[i][j] != matrix[row][col])
                    {
                        return false;
                    }
                    row++,col++;
                }
            }
        }
        return true;
    }
};