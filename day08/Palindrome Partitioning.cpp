
bool isPalindrome(string &s, int start, int end){
    while(start<=end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void helper(int index, string &s, vector<vector<string>> &ans, vector<string> &temp){
    if(index == s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=index; i<s.size(); i++){
        if(isPalindrome(s, index, i)){
            temp.push_back(s.substr(index, i-index+1));
            helper(i+1, s, ans, temp);
            temp.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> temp;
    helper(0, s, ans, temp);
    return ans;
}