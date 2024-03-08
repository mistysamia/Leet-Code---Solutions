class Solution
{
    pair<int, int> path[100][100];
    int vis[101][101];
    int visited[101][101];
#define pii pair<int, int>
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int sourcex = 0, sourcey = 0, desx = grid.size() - 1, desy = grid.size() - 1;
        if (desx == 0)
        {
            return 1;
        }
        // cout << "Sour " << desx << " " << desy << endl;
        memset(vis, 0, sizeof vis);
        memset(path, 0, sizeof path);
        memset(visited, -1, sizeof visited);
        int fx[] = {1, -1, 0, 0, -1, 1, -1, 1};
        int fy[] = {0, 0, 1, -1, -1, -1, 1, 1};
        vis[sourcex][sourcey] = 0;
        visited[sourcex][sourcey] = 1;
        queue<pii> q;
        q.push({0, 0});
        while (!q.empty())
        {
            pii top = q.front();
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int tx = top.first + fx[k];
                int ty = top.second + fy[k];
                // cout << "In " << tx << " " << ty << endl;
                if (tx >= 0 && tx < grid.size() && ty >= 0 &&
                    ty < grid.size() && grid[tx][ty] == 0)
                {
                    if (visited[tx][ty] == -1)
                    {
                        visited[tx][ty] = 1;
                        vis[tx][ty] = vis[top.first][top.second] + 1;
                        q.push({tx, ty});
                        if (tx == desx && ty == desy)
                            return vis[tx][ty] + 1;
                    }
                }
                //  cout << tx << " " << ty << endl;
            }
        }
        return -1;
    }
};