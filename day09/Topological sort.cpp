
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans; // create ans array
	    queue<int> q; // store temp answer
	    
	    vector<int> indegree(V, 0); // claculates indegree of each vertex
	    for(int i=0; i<V; i++){ 
	        vector<int> data = adj[i]; // data stores like adj[0]->data={}, adj[1]->data={0}, adj[2]->data={0}
	        for(auto x: data){
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){       //if indegeree is 0 put it into the queue
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int u = q.front();          //store it in u, pop u, then push it into ans
	        q.pop();
	        ans.push_back(u);
	        
	        for(auto v: adj[u]){        //check its neighbours
	            indegree[v]--;          //as u is gone hence its indegree is reduced by one
	            if(indegree[v] == 0){
	                q.push(v);
	            }
	        }
	    }
	    return ans;
	}

