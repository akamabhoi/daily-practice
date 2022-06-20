bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(source);
        visited[source] == true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == destination) return true;
            for(auto ele : adj[curr]){
                if(!visited[ele]){
                    visited[ele] = true;
                    q.push(ele);
                }
            }
        }
        
        
        return false;
    }