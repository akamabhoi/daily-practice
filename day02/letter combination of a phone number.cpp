void helper(string s, string temp, int i, vector<string> &keys, vector<string> &ans){
    
    if(i == s.size()){
        ans.push_back(temp);
        return;
    }
    //important remember
    for(int j=0; j<keys[s[i]-'0'].size(); j++){
        helper(s, temp+keys[s[i]-'0'][j], i+1, keys, ans);
    }
}

vector<string> combinations(string s){
	//store keys
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs", "tuv", "wxyz"};
    //store ans
    vector<string> ans;
	
    if(s == ""){
        return ans;
    }
    
    helper(s, "", 0, keys, ans);
    return ans;
	
}
