void genBra(string ans, int open, int close, int n, int i){
    if(i == 2*n){
        cout << ans << endl;
        return;
    }
    if(open < n){
        genBra(ans+'{',open+1, close, n, i+1);
    }
    if(close<open){
        genBra(ans+'}', open, close+1, n, i+1);
    }
}


void printParantheses(int n) {
    // Write your code here
    string ans;
    genBra(ans, 0, 0, n, 0);
}