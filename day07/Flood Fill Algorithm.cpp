/*
1. In this problem, we need to change the old color of a cell, starting from (x,y), with the newColor given in the question. 
We should only colour those cells which have the old colour and not any other cell. And we should always be within the boundaries of the grid.
2. One edge case will be if newColor== oldColor. In that case, we don't need to change anything simply return the 2D image vector
3. If not we will use recursion to color all the cells having oldColor with newColor. 
4. Base cases will be pretty simple. We need to stay within the boundaries of the grid and we should change only those grids who have oldColor.
    if (i < 0 || i>=m || j<0 || j>=n || image[i][j] != oldColor)
    return;
5. Now we need to move on 4 directions - up,down,left,right and ask recursion to color all the remaining cells having color as oldColor. 

Time Complexity: O(M*N) [ In worst case, we need to traverse the entire grid because all the cells might be having oldColor]
Space Complexity: O(M*N) [ In worst case we start from (0,0) and pain the entire grid with newColor. This causes the recursive stack space equal to O(M*N)]
*/
void helper(vector<vector<int>> &image, int newColor,int oldColor, int i, int j, int m, int n){
    
    if(i<0 or j<0 or i>=m or j >=n or image[i][j] != oldColor) return;
    image[i][j] = newColor;
    helper(image, newColor, oldColor, i+1, j, m, n);
    helper(image, newColor, oldColor, i-1, j, m, n);
    helper(image, newColor, oldColor, i, j+1, m, n);
    helper(image, newColor, oldColor, i, j-1, m, n);
}


vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int oldColor = image[x][y];
    if(oldColor == newColor) return image;
    helper(image, newColor, oldColor, x, y, image.size(), image[0].size());
    return image;
    
}