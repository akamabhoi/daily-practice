bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    while (!q.empty())
    {
        int room = q.front();
        q.pop();
        for (auto key : rooms[room])
        {
            if (!visited[key])
            {
                visited[key] = true;
                q.push(key);
            }
        }
    }
    for (auto data : visited)
    {
        if (!data)
        {
            return data;
        }
    }
    return true;
}