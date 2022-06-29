// Function to check if cell indexes are within bounds.
bool isValid(int i, int j, int n, vector<vector<bool>> &visited)
{
    if (i >= 0 and j >= 0 and i < n and j < n and visited[i][j] == false)
    {
        return true;
    }
    return false;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    int n = N;
    int x1 = KnightPos[0] - 1;
    int y1 = KnightPos[1] - 1;
    int xt = TargetPos[0] - 1;
    int yt = TargetPos[1] - 1;
    if (x1 == xt and y1 == yt)
        return 0;
    // using boolean list to mark visited cells and currently
    // marking all the cells as false.
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    // queue for storing visited cells by knight in board and steps taken.
    queue<pair<int, int>> q;
    int ans = 0;
    // pushing starting position of knight with 0 distance.
    q.push({x1, y1});
    visited[x1][y1] = true;
    while (!q.empty())
    {
        ans++;
        int q_size = q.size();
        while (q_size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int xx = p.first;
            int yy = p.second;

            int x_dir[8] = {1, 2, 2, 1, -1, -2, -2, -1};
            int y_dir[8] = {2, 1, -1, -2, -2, -1, 1, 2};
            // using loop to reach all the cells that can be reached by knight.
            for (int i = 0; i < 8; i++)
            {
                int nx = xx + x_dir[i];
                int ny = yy + y_dir[i];
                // if we reach the required cell, we return ans.
                if (nx == xt && ny == yt)
                    return ans;
                // if cell indexes are valid and cell is not visited, we push the
                // indexes in queue with steps and mark cell as visited.
                if (isValid(nx, ny, n, visited))
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return ans;
}
