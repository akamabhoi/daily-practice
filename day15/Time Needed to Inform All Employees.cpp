unordered_map<int, vector<int>> mp;
int mx = 0;
int ans = 0;

void dfs(int manager, vector<int> &informTime)
{
    mx = max(mx, ans);
    for (auto employee : mp[manager])
    {
        ans += informTime[manager];
        dfs(employee, informTime);
        ans -= informTime[manager];
    }
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    for (int i = 0; i < n; i++)
    {
        int m = manager[i];
        if (m != -1)
        {
            mp[m].push_back(i);
        }
    }
    dfs(headID, informTime);
    return mx;
}