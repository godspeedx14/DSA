```cpp
/*
 * Core Idea: This function vertically reverses a k x k submatrix within the given grid.
 *            It takes the starting top-left corner (x, y) and swaps elements from the
 *            top half of the submatrix with their corresponding elements in the bottom half.
 *
 * Time Complexity: O(k^2)
 *   The nested loops iterate approximately k/2 times for rows and k times for columns,
 *   performing a constant-time swap operation in each iteration.
 * Space Complexity: O(1)
 *   The function modifies the grid in-place and uses a constant amount of extra space
 *   for variables.
 */
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {  
        int r=k/2;
        for (int i=0;i<r;i++)
            for (int j=0;j<k;j++)
                {
                    swap(grid[x+i][y+j], grid[x+k-1-i][y+j]);
                }

        return grid;
        
    }
};
```