/*
1. This question is very similar to the Combination question
2. In place of having exactly k elements in a subset, we have to put those Subsets which have sum equal to TargetSum
3. For that we need to keep calculating currentSum which calculates the current sum of each subset.
4. An element can be picked for any number of times we want.
5. Three Base conditions will be there:
    a) if(currentSum == target)
        Put the subset in ans[][] and return
    b) if(currentSum > target)
        We cannot get our targetSum, so we simply return
    c) if(i >= arr.size() )
        We have traversed the entire array and still hasn't found the Target, so we simply return
6.As we can pick a element for any number of times then the Recursive calls will be such:
    a) Pick the Element, include it in the subset and increment currentSum by currentSum+ = arr[i]
    b) Back-track, un do the changes we did to both currentSum and subset
    c) Don't pick the element, and call for i+1
*/




#include<bits/stdc++.h>
void helper(vector<int>& arr, int targetSum, int i, vector<vector<int>> &ans, vector<int> &temp, int currSum){
    if(currSum == targetSum){
        ans.push_back(temp);
        return;
    }
    if(currSum > targetSum) return;
    if(i >= arr.size()) return;
    
    currSum += arr[i];
    temp.push_back(arr[i]);
    helper(arr, targetSum, i, ans, temp, currSum);
    currSum -= arr[i];
    temp.pop_back();
    helper(arr, targetSum, i+1, ans, temp, currSum);
    
}

vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    int currSum = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    sort(ARR.begin(), ARR.end());
    helper(ARR, B, 0, ans, temp, currSum);
    
    return ans;
}
