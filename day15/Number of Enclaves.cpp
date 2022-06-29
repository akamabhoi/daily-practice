void dfs(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    if (i < 0 or j < 0 or i == m or j == n or grid[i][j] == 0)
    {
        return;
    }
    grid[i][j] = 0;
    // down
    dfs(i + 1, j, m, n, grid);
    // left
    dfs(i, j - 1, m, n, grid);
    // right
    dfs(i, j + 1, m, n, grid);
    // up
    dfs(i - 1, j, m, n, grid);
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // top and bottom (left to right)
    for (int j = 0; j < n; j++)
    {
        if (grid[0][j])
        {
            dfs(0, j, m, n, grid);
        }
        if (grid[m - 1][j])
        {
            dfs(m - 1, j, m, n, grid);
        }
    }

    // left and right (top to bottom)
    for (int i = 0; i < m; i++)
    {
        if (grid[i][0])
        {
            dfs(i, 0, m, n, grid);
        }
        if (grid[i][n - 1])
        {
            dfs(i, n - 1, m, n, grid);
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                count++;
            }
        }
    }
    return count;
}