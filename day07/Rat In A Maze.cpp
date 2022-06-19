/*
Whenever we want to generate all possible paths or answers, we need to think in terms of Recursion and Backtracking. Backtracking is simply undoing the change which we have already done. 

Summary:
1. We(mouse) are standing at (0,0) and we need to generate all possible paths so that the mouse reachers the last cell of the maze (n-1,n-1)
2. We are allowed to move in 4 directions only- Up, Down, Left and Right. We need to return a vector<string> ans containing all possible paths through which the mouse can reach the end of maze. 
3. Base conditions are pretty simple. Firstly, we cannot go beyond the boundaries of the matrix, secondly we cannot go to a cell which contains a blockage that is, matrix[i][j] denotes a blockage or wall and we cannot go through it. Also we need to mark every cell as visited with any other value(marked with 0 for better understanding) such that we don't come back to the same cell again and again. Lastly, when we reach the target cell (n-1,n-1) we need to put our path string in ans[] vector and return as we have completed our objective.
a) if(i <0 || j<0 || i>=n || j>=n)
     return;
b) if(matrix[i][j] == 0)
     return;
c) if(i==n-1 && j==n-1)
{ 
     ans.push_back(path);
     return;
}
4. Now, we have four options. But according to the problem we need to print the paths in sorted manner so we will move like- Down, Left, Right, Up. And before that we will mark the cell as visited by matrix [i][j] = 0 and Back-track at the end. 
// Mark as visited
matrix[i][j] = 0;
// Move Down
help(i+1,j,path+'D');
// Move Left
help(i,j-1,path +'L');
//Move Right
help(i,j+1,path + 'R');
// Move Up
help(i-1,j,path+'U);

// Undo the change
matrix[i][j] = 1;
5. Recursion will generate all the possible paths to reach end. We don't have to do anything else.

Time Complexity: O(4^n*n) [ Because in worst case we will have a maze all filled with 1 and we will traverse all the cells to reach the end. And we have n*n cells in the maze and for each cell we have 4 option that's why Time Complexity is O(4^n*n) ]

Space Complexity: O(n*n)
[ This is equal to the height of the Recursive Tree and since we need to reach the end (n-1,n-1) from (0,0) that's why we need to traverse the entire matrix. ]
*/


#include<bits/stdc++.h>
void helper(vector<vector<int>> &arr, int n, int i, int j, vector<string> &ans, string &temp){
    if(i==n-1 and j==n-1){
        ans.push_back(temp);
        return;
    }
    if(i<0 or j<0 or i == n or j == n or arr[i][j] == 0) return;
    
    arr[i][j] = 0;
    //up
    temp.push_back('U');
    helper(arr, n, i-1, j, ans, temp);
    temp.pop_back();
    //left
    temp.push_back('L');
    helper(arr, n, i, j-1, ans, temp);
    temp.pop_back();
    //right
    temp.push_back('R');
    helper(arr, n, i, j+1, ans, temp);
    temp.pop_back();
    //down
    temp.push_back('D');
    helper(arr, n, i+1, j, ans, temp);
    temp.pop_back();
    
    arr[i][j] = 1;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    string temp;
    helper(arr, n, 0, 0, ans, temp);
    sort(ans.begin(), ans.end());
    return ans;
}