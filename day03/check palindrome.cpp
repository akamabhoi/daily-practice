bool helper(int start, int end, string &s){
    if(start >= end) return true;
    
    if(s[start] != s[end]){
        return false;
    }
    else{
        helper(start+1, end-1, s);
    }
}

bool isPalindrome(string &s)
{
	
    return helper(0, s.size()-1, s);
}