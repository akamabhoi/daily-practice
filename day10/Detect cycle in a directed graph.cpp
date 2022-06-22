bool helper(int s, vector<bool> &visited, vector<bool> &cyclicVisited, vector<int> adj[])
{
    visited[s] = true;
    cyclicVisited[s] = true;

    for (auto v : adj[s])
    {
        if (!visited[v])
        {
            if (helper(v, visited, cyclicVisited, adj))
            {
                return true;
            }
        }
        else if (visited[v] and cyclicVisited[v])
        {
            return true;
        }
    }
    cyclicVisited[s] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false);
    vector<bool> cyclicVisited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (helper(i, visited, cyclicVisited, adj)) // if cycle present returns true
            {
                return true;
            }
        }
    }
    return false;
}
