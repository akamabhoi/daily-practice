
    vector<vector<int>> ans; // intialise answer vector
    
    bool isSafe(vector<vector<int>> &board, int r, int c, int n){
        
        //for directly up checking
        for(int i=0; i<r; i++){
            if(board[i][c] == 1){
                return false;
            }
        }
        
        //for checking towards diagonally left up 
        for(int i=r-1, j=c-1; i>=0 and j>=0; i--, j--){
            if(board[i][j] == 1){
                return false;
            }
        }
        // for checking towards diagonally right up
        for(int i=r-1, j=c+1; i>=0 and j<n; i--, j++){
            if(board[i][j] == 1){
                return false;
            }
        }
        
        return true;
    }
    
    void helper(vector<vector<int>> &board, int r, int n){
        //base condition which checks if we reach end of the row we shall check and insert it into temp and then ans
        if(r == n){
            vector<int> temp;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j] == 1){
                        temp.push_back(j+1);
                    }
                }
            }
            ans.push_back(temp);
            return;
        }
        // goes on checking each eow and column and puts 1 if it is fine and calls helper by increasing a row
        for(int i=0; i<n; i++){
            if(isSafe(board, r, i, n)){
                board[r][i] = 1;
                helper(board, r+1, n);
                //backtrack
                board[r][i] = 0;
            }
        }
        
        
    }
    
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> board(n, vector<int>(n, 0));
        helper(board, 0, n);
        return ans;
    }

