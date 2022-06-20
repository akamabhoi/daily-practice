/*
Intuition:
Consider trust as a graph, all pairs are directed edge.
The point with in-degree - out-degree = N - 1 become the judge.

Explanation:
Count the degree, and check at the end.

Time Complexity:
Time O(T + N), space O(N)
*/




    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> data(n+1,0);
        for(auto count: trust){
            data[count[0]]--;
            data[count[1]]++;
        }
        for(int i=1; i<=n; i++){
            int x = data[i];
            if(x == n-1){
                return i;
            }
        }
        return -1;
    }
