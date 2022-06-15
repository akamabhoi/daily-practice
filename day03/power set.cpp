//a set of all possible subsets of 'ARR'.

#include<bits/stdc++.h>
void helper(vector<int> &v, int i, vector<vector<int>> &ans, vector<int> &temp){
    if(i == v.size()){
        ans.push_back(temp);
        return;
    }
    //pick the element
    temp.push_back(v[i]);
    helper(v, i+1, ans, temp);
    //not pick
    temp.pop_back();
    helper(v, i+1, ans, temp);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    vector<int> temp;
    helper(v, 0, ans, temp);
    sort(ans.begin(), ans.end());
    return ans;
}