// Steps to Solve :
// 1. Move over the boundary of board, and find O's
// 2. Every time we find an O, perform DFS from it's position
// 3. In DFS convert all 'O' to 'B'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)
// 4. After all DFSs have been performed, board contains three elements,B,O and X
// 5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
// 6. 'B' are elements which cannot be flipped to 'X', so flip them back to 'O'

void dfs(vector<vector<char>> &board, int i, int j, int m, int n)
{
    if (i < 0 or j < 0 or i == m or j == n or board[i][j] != 'O')
    {
        return;
    }
    board[i][j] = 'B';
    dfs(board, i + 1, j, m, n);
    dfs(board, i, j + 1, m, n);
    dfs(board, i - 1, j, m, n);
    dfs(board, i, j - 1, m, n);
}
void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    // top (left to right)
    for (int i = 0; i < n; i++)
    {
        if (board[0][i] == 'O')
        {
            dfs(board, 0, i, m, n);
        }
    }
    // bottom (left to right)
    for (int i = 0; i < n; i++)
    {
        if (board[m - 1][i] == 'O')
        {
            dfs(board, m - 1, i, m, n);
        }
    }
    // left (top to bottom)
    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
        {
            dfs(board, i, 0, m, n);
        }
    }
    // right (top to bottom)
    for (int i = 0; i < m; i++)
    {
        if (board[i][n - 1] == 'O')
        {
            dfs(board, i, n - 1, m, n);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'B')
            {
                board[i][j] = 'O';
            }
        }
    }
}