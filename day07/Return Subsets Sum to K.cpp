
void helper(vector<int> arr, int n, int k, int i, vector<vector<int>> &ans, vector<int> &temp){
    if(i == n){
        if(k == 0){
            ans.push_back(temp);
            return;
        }
    }
    else{
    temp.push_back(arr[i]);
    helper(arr, n, k-arr[i], i+1, ans, temp);
    temp.pop_back();
    helper(arr, n, k, i+1, ans, temp);
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;
    helper(arr, n, k, 0, ans, temp);
    return ans;
}