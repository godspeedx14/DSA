```cpp
/*
 * Core Idea:
 * This solution uses a 2D prefix sum array to efficiently calculate the sum of submatrices anchored at the top-left corner (0,0) of the grid.
 * `sum[i][j]` stores the total sum of elements from `grid[0][0]` to `grid[i-1][j-1]`.
 * It iterates through all possible bottom-right corners `(i-1, j-1)` for these submatrices.
 * If the calculated submatrix sum `sum[i][j]` is less than or equal to `k`, it increments the count.
 * An optimization breaks the inner loop if `sum[i][j]` exceeds `k`, assuming non-negative grid values mean further sums in that row will also exceed `k`.
 *
 * Time Complexity: O(R * C)
 * The algorithm iterates through each cell of the grid once to calculate prefix sums and check conditions.
 *
 * Space Complexity: O(R * C)
 * An auxiliary 2D array `sum` of size (R+1) x (C+1) is used to store prefix sums.
 */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if (grid[0][0]>k) return 0;

        int r=grid.size(),c=grid[0].size();

        vector<vector<int>> sum(r+1,vector<int>(c+1,0));

        int res=0;

        for(int i=1;i<r+1;i++)
            for(int j=1;j<c+1;j++)
                {
                    sum[i][j]=grid[i-1][j-1] -sum[i-1][j-1] +sum[i-1][j] +sum[i][j-1];
                    if(sum[i][j]<=k)res++;
                    else break;
                }

        return res;
            
    }
};
```