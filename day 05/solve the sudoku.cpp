
    
    bool check(int grid[N][N], int row, int col, int num){
        //row
        for(int i=0; i<9; i++){
            if(grid[row][i] == num) return false;
        }
        //col
        for(int i=0; i<9; i++){
            if(grid[i][col] == num) return false;
        }
        //box
        int ini = row - row%3;
        int inj = col - col%3;
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[ini+i][inj+j] == num) return false;
            }
        }
        return true;
    }
    
    
    bool helper(int grid[N][N], int row, int col){
        if(row == 9) return true;
        if(col == 9) return helper(grid, row+1, 0);
        if(grid[row][col] != 0) return helper(grid, row, col+1);
        
        for(int i=1; i<=9; i++){
            if(check(grid, row, col, i)){
                grid[row][col] = i;
                if(helper(grid, row, col+1)){
                    return true;
                }
            }
            grid[row][col] = 0;
        }
        return false;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return helper(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        SolveSudoku(grid);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << grid[i][j] << " ";
            }
        }
    }
};
