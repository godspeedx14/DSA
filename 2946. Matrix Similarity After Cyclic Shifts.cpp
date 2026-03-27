```cpp
// Core idea: Determine if each row of the matrix remains identical after a specific circular shift.
// Even-indexed rows are checked against a left circular shift by `k`, and odd-indexed rows against a right circular shift by `k`.
// Time complexity: O(rows * cols)
// Space complexity: O(1)
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
```