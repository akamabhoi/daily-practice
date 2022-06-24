void helper(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &temp, int s)
{
    temp.push_back(s);

    if (s == graph.size() - 1)
    {
        ans.push_back(temp);
        return;
    }

    for (auto x : graph[s])
    {
        helper(graph, ans, temp, x);
        temp.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(graph, ans, temp, 0);
    return ans;
}
