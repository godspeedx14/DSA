/**
 * Core idea: Checks if each row of the matrix is cyclically invariant to a k-shift.
 *            Even-indexed rows are compared against a k-position left shift,
 *            while odd-indexed rows are compared against a k-position right shift.
 * Time complexity: O(n * m), where n is the number of rows and m is the number of columns.
 * Space complexity: O(1).
 */
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();

        for(int i=0;i<n;i++)
            {int x, y=(i%2)?k:-k;
                for (int j=0;j<m;j++)
                    {x=(m+((j+y)%m))%m;if(mat[i][j]!=mat[i][x])return false;}
            }
        
        return true;
                
    }
};