

void helper(vector<vector<char>> &grid, int i, int j, int m, int n)
{
    if (i < 0 or j < 0 or i == m or j == n or grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    // down
    helper(grid, i + 1, j, m, n);
    // left
    helper(grid, i, j - 1, m, n);
    // right
    helper(grid, i, j + 1, m, n);
    // up
    helper(grid, i - 1, j, m, n);
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                helper(grid, i, j, m, n);
                ++count;
            }
        }
    }
    return count;
}
