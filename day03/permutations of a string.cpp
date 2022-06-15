#include<bits/stdc++.h>
void helper(string &str, int pos, vector<string> &ans){
    if(pos == str.size()){
        ans.push_back(str);
        return;
    }
    //bring all elements(i) to pos
    for(int i=pos; i<str.size(); i++){
        swap(str[i], str[pos]);
        helper(str, pos+1, ans);
        //backtrack
        swap(str[i], str[pos]);
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector <string> ans;
    helper(str, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}