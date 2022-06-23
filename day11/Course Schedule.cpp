
bool isCyclePresent(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<bool> &currVisited)
{
    visited[s] = true;
    currVisited[s] = true;

    for (auto v : adj[s])
    {
        if (!visited[v])
        {
            if (isCyclePresent(adj, v, visited, currVisited))
            {
                return true;
            }
        }
        else if (visited[v] and currVisited[v])
        {
            return true;
        }
    }
    currVisited[s] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto data : prerequisites)
    {
        // u <- v
        int u = data[0];
        int v = data[1];
        adj[v].push_back(u);
    }

    int v = numCourses;
    vector<bool> visited(v, false);
    vector<bool> currVisited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (isCyclePresent(adj, i, visited, currVisited))
            {
                return false;
            }
        }
    }
    return true;
}
