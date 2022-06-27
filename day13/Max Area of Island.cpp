void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int &count)
{
    if (i < 0 or j < 0 or i == m or j == n or grid[i][j] != 1)
    {
        return;
    }
    grid[i][j] = 0;
    count++;
    // d
    dfs(grid, i + 1, j, m, n, count);
    // l
    dfs(grid, i, j - 1, m, n, count);
    // r
    dfs(grid, i, j + 1, m, n, count);
    // u
    dfs(grid, i - 1, j, m, n, count);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int maxCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                dfs(grid, i, j, m, n, count);
                maxCount = max(maxCount, count);
            }
        }
    }
    return maxCount;
}
