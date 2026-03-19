```cpp
/**
 * Core idea:
 * This solution counts the number of submatrices (anchored at top-left (0,0))
 * where the total count of 'X' characters equals the total count of 'Y'
 * characters, and both counts are positive. It uses 2D prefix sum arrays
 * to efficiently calculate character counts for each potential submatrix.
 *
 * Time complexity: O(N * M)
 *    Iterates through each cell of the N x M grid once to compute prefix sums
 *    and check the condition.
 *
 * Space complexity: O(N * M)
 *    Uses two additional N x M 2D arrays to store prefix sums for 'X' and 'Y' characters.
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