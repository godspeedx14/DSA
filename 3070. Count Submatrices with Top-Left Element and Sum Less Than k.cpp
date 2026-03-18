```cpp
/*
Core Idea:
This solution counts submatrices that start at (0,0) and end at (i,j) such that their sum is less than or equal to 'k'.
It utilizes a 2D prefix sum technique to efficiently calculate the sum of each such submatrix.
The `sum[i][j]` entry stores the sum of elements in the submatrix from `grid[0][0]` to `grid[i-1][j-1]`.
Since grid elements are typically non-negative in such problems, if a submatrix sum exceeds 'k', any larger submatrices extending further in the same row will also exceed 'k', allowing for an optimization to break early from the inner loop.

Time Complexity: O(R * C)
We iterate through each cell of the grid at most once to compute prefix sums and check the condition. R is the number of rows, C is the number of columns.

Space Complexity: O(R * C)
An auxiliary 2D array `sum` of size (R+1) x (C+1) is used to store prefix sums.
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