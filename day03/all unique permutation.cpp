#include<bits/stdc++.h>

void helper(vector<int> &arr, int n, int pos, vector<vector<int>> &ans){
    if(pos == n){
        ans.push_back(arr);
    }
    //this is made to check duplicate
    unordered_set<int> mp;
    for(int i=pos; i<n; i++){
        //if duplicate then continue or skip this loop
        if(mp.find(arr[i]) != mp.end()) continue;
        mp.insert(arr[i]);
        //rest same question as finding all permutaions of a given string
        swap(arr[i], arr[pos]);
        helper(arr, n, pos+1, ans);
        swap(arr[i], arr[pos]);
    }
}


vector<vector<int> > uniquePermutations(vector<int> &arr, int n) {
	
    vector<vector<int>> ans;
    helper(arr, n, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}