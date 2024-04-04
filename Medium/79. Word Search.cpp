int fx[4] = {0, -1, 0, 1};
int fy[4] = {-1, 0, 1, 0};

bool backtrack(vector<vector<char>> &board, string word, int i, int j, int wordIndx, vector<vector<bool>> &visited)
{
    if (wordIndx == word.size())
        return true;

    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[wordIndx] || visited[i][j])
        return false;

    visited[i][j] = true;

    bool ans = false, temp = false;
    for (int indx = 0; indx < 4; indx++)
    {
        int x = fx[indx] + i;
        int y = fy[indx] + j;
        temp = backtrack(board, word, x, y, wordIndx + 1, visited);
        ans = temp || ans;
    }

    visited[i][j] = false;
    return ans;
}

bool exist(vector<vector<char>> &board, string word)
{
    bool ans = false;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            ans = backtrack(board, word, i, j, 0, visited);
            if (ans)
                return true;
        }
    }
    return false;
}