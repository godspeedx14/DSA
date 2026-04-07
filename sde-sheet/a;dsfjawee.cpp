```cpp
/*
 * Core Idea:
 * This solution counts submatrices that start from (0,0) and end at (i,j) (for all valid i,j) 
 * such that they contain an equal and positive number of 'X' and 'Y' characters.
 * It uses two 2D prefix sum arrays to efficiently calculate the cumulative counts of 'X's and 'Y's
 * from the top-left corner (0,0) to any given (i,j) in the original grid.
 *
 * Time Complexity: O(N * M)
 *   - N and M are the dimensions of the input grid.
 *   - The algorithm iterates through each cell of the grid once to populate the prefix sum arrays and check the condition.
 *
 * Space Complexity: O(N * M)
 *   - N and M are the dimensions of the input grid.
 *   - Two 2D prefix sum arrays of size (N+1)x(M+1) are used to store cumulative counts.
 */
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),cnt=0;
        vector<vector<int>> x(n+1,vector<int>(m+1,0)),y(n+1,vector<int>(m+1,0));
        for (int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                x[i][j]=x[i-1][j]+x[i][j-1]+(grid[i-1][j-1]=='X') - x[i-1][j-1];
                y[i][j]=y[i-1][j]+y[i][j-1]+(grid[i-1][j-1]=='Y') - y[i-1][j-1];
                if(x[i][j]==y[i][j] && x[i][j]>0)cnt++;
            }
        }

        return cnt;
    }
};
```