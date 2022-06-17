/*
1. This question uses all the concepts of subsets and combinations we have studied so far.
2. In this problem, we need to generate all the words possible from the number of keypad given by the user as input
3. To solve this problem, we firstly need vector of strings which store alphabets corresponding to the indices. 
4. Now we need to create a function help which takes the given string s, ans vector to store all the answers, i to iterate over given string and a temp string to store the current word we are making. Everything is passed by reference to save space. 
5. If i reaches to s.size(), it means we have traversed the entire string, so we put the temp word inside the ans vector and return.
6. Else we would pick a string str = keys[s[i]-'0'] . This will represent all the letters represented by i-th character of string s. 
7. We run a for loop for j = 0 till j < str.size() and we add str[j] character inside our temp string and ask Recursion to solve for i+1th character.
8. Lastly, we return ans vector from our given function.

Time complexity: O(3^N) [ As most of the letters has 3 choices so we can approximately say time complexity as 3^N]

Space Complexity: O(N) [ N is the size of the given string. This is because we can only process till i < s.size() , that's why Space Complexity is O(N)]
*/



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
