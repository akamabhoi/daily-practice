/*
1. This question is a variation of generating all possible subsets
2. Here we have been given a value k and n and we need to generate all possible subsets starting from i = 1 till i <= n of size k.
3. We would still be using our same logic-  pick an element, backtrack and pop it out and don't pick the element.
4. The above basic approach will be to generate all possible subsets. Time complexity will definitely be O(2^N)
5. A slight improvement from our side can be, we can check if subset.size() == k, that is, if our current Subset already has k elements, we can simply put it in our ans vector and return. 
     Can also be used as if(k==0) if we are returning k-1 in  pick condition.
6. In the most optimised version, we can check if we have greater than or equal to k elements to process or not. That is to say, if k becomes greater than (n-i+1) elements, this means no matter if we pick all the remaining elements, we still cannot generate a subset of size k. In this way, we can return directly avoiding smaller subsets.
7. In this way, we can improve the run time of our answer. The Time Complexity is still calculated based on worst case so it will still be O(2^N).

Time Complexity: O(2^N) [in worst case]
Space Complexity: O(N) [ for recursive stack] + O(N^2) [ for storing all the subsets in ans vector, in worst case k == n]
*/
void helper(int n, int k, int i, vector<vector<int>> &ans, vector<int> &temp){
    if(k == 0){
        ans.push_back(temp);
        return;
    }
    if(i > n) return;
    
    
    temp.push_back(i);
    helper(n, k-1, i+1, ans, temp);
    temp.pop_back();
    helper(n, k, i+1, ans, temp);
}

vector<vector<int>> combinations(int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;
    helper(n, k, 1, ans, temp);
    return ans;
}