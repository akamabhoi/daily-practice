/*
1. Question is similar to Flood Fill algorithm
2. We need to find a word in the given board of size (m*n)
3. So we need to iterate over the board [][] and check if word is present inside or not.
4. Instead of using visited matrix, we mark all the visited cells with '$' and upon backtracking    we need to undo the change we have done earlier.
5. We will have three base cases:
    a) if(k == word.size() )
         return true;
    b) if(i <0 || j<0 || i >=m || j>= n)
        return false;
c) if(board[i][j] != word[k] || board [i][j] == '$')
    return false;
6. Else we mark the cell as visited using '$' and move in all possible directions Up(i-1,j) ,      Down (i+1,j), Left(i,j-1) and Right (i,j+1) and ask Recursion to check whether the              remaining part of word is present or not from k+1 till word.size()
7. At the end, backtrack and undo the change and return OR of all the four options.
   return Op1 || Op2 || Op3 || Op4 ;

Time Complexity: O(m*n * 4^k) [ k is word.size(). This is because, in worst case, we traverse the entire board[][] and for each call we have 4 choices and in the Worst case we will go till word.size() ]

Space Complexity: O(k) [ k is word.size()]

*/

bool helper(vector<vector<char>> &board, string &word, int n, int m, int i, int j, int k){
    if(k == word.size()) return true;
    if(i<0 or j<0 or i==n or j==m or board[i][j] != word[k]) return false;
    board[i][j] = '$';
    bool op1 = helper(board, word, n, m, i+1, j, k+1);
    bool op2 = helper(board, word, n, m, i-1, j, k+1);
    bool op3 = helper(board, word, n, m, i, j+1, k+1);
    bool op4 = helper(board, word, n, m, i, j-1, k+1);
    board[i][j] = word[k];
    return op1 or op2 or op3 or op4;
}


bool present(vector<vector<char>> &board, string word, int n, int m) 
{
    // Write your code here
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                if(helper(board, word, n, m, i, j, 0)) return true;
            }
        }
        
    }
    return false;
}