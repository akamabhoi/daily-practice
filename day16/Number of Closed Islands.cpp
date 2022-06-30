void dfs(int i, int j, int m, int n, vector<vector<int>> &grid)
{

    if (i < 0 or j < 0 or i == m or j == n or grid[i][j] != 0)
    {
        return;
    }
    grid[i][j] = 1;
    // down
    dfs(i + 1, j, m, n, grid);
    // left
    dfs(i, j - 1, m, n, grid);
    // right
    dfs(i, j + 1, m, n, grid);
    // up
    dfs(i - 1, j, m, n, grid);
}

int closedIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i * j == 0 or i == m - 1 or j == n - 1)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, m, n, grid);
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                count++;
                dfs(i, j, m, n, grid);
            }
        }
    }
    return count;
}