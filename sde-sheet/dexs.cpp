```cpp
/*
 * Core Idea:
 * This solution counts the number of submatrices (starting from the top-left corner (0,0))
 * where the total count of 'X' characters equals the total count of 'Y' characters,
 * and both counts are greater than zero. It uses 2D prefix sums to efficiently calculate
 * the counts of 'X's and 'Y's for each submatrix ending at (i,j).
 *
 * Time Complexity: O(N * M)
 *   - N is the number of rows and M is the number of columns in the grid.
 *   - A single pass iterates through each cell of the grid to compute prefix sums.
 *
 * Space Complexity: O(N * M)
 *   - Two auxiliary 2D arrays of size (N+1) x (M+1) are used for prefix sums.
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