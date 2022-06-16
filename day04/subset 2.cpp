/*
1. In Subsets-I, we have all the elements as unique. That's why our Pick and Don't Pick conditions were working fine.
2. In Subsets-II, we will have duplicate elements. But we want our final ans to contain only unique subsets.
3. We can achieve it by counting only one occurrence of an element and skipping all its rest occurrences in arr[]
4. We need to first sort the given vector arr[]
5. For don't pick condition, we will first check whether arr[i]==arr[i+1] or not. If so, we will ignore the rest occurrences of that particular element.
6. Time and Space Complexity will remain same[in worst case we will have unique elements only]
*/




#include<bits/stdc++.h>

void helper(int n, vector<int> &arr, int i, vector<vector<int>> &ans, vector<int> &temp){
    if(i == n){
        ans.push_back(temp);
        return;
    }
    //pick
    temp.push_back(arr[i]);
    helper(n, arr, i+1, ans, temp);
    temp.pop_back();
    
    //not pick
    while(i+1 < n and arr[i] == arr[i+1]) i++;
    helper(n, arr, i+1, ans, temp);
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    helper(n, arr, 0, ans, temp);
    sort(ans.begin(), ans.end());
    return ans;
}