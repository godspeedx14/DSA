```cpp
// Core idea: Pre-calculate the count of 1s for each row and column. A cell (i, j) is special if mat[i][j] is 1, and it is the unique 1 in its row and the unique 1 in its column.
// Time complexity: O(n * m), where n is the number of rows and m is the number of columns, due to two passes over the matrix.
// Space complexity: O(n + m) for storing row and column sums.
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> r(n,0) , c(m,0);
        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    r[i]+=mat[i][j];
                    c[j]+=mat[i][j];    
                }


        int ans=0;

        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (mat[i][j]==1 && r[i] == 1 && c[j]==1)
                    ans++;
                

        return ans;
        
    }
};
```