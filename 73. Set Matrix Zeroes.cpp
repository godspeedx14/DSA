```cpp
/**
 * Core idea: This algorithm uses the first row and first column of the matrix itself to mark which rows and columns need to be zeroed.
 * It first checks if the original first row or column contain any zeros and stores this information separately.
 * Then, it iterates through the rest of the matrix, using matrix[i][0] and matrix[0][j] as flags if matrix[i][j] is zero.
 * Finally, it updates the cells based on these flags, carefully handling the first row and column using the stored original state.
 * Time complexity: O(N*M), where N is the number of rows and M is the number of columns.
 * Space complexity: O(1), as the modifications are done in-place.
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size(),m=matrix[0].size();

        bool flg=false,flg1=false;
        //any 0 in first col 
        for(int i =0;i<n;i++)
            if(matrix[i][0]==0) {flg=true; break;}

        //any 0 in first row 
        for(int j =0;j<m;j++)
            if(matrix[0][j]==0) {flg1=true; break;}

        for (int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    if (matrix[i][j]==0) matrix[i][0]=0,matrix[0][j]=0;
                }

        for (int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if (matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;

        if (flg)  for(int i =0;i<n;i++) matrix[i][0]=0;
        if (flg1)  for(int j =0;j<m;j++) matrix[0][j]=0;
        
    }
};
```