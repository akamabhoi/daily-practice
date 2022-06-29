void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    visited[s] = true;
    for (auto v : adj[s])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs(adj, visited, v);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (isConnected[i][j])
                {
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                }
            }
        }
    }

    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(adj, visited, i);
        }
    }
    return count;
}