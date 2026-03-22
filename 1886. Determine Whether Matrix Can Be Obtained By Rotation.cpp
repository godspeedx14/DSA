```c++
/*
 * Core Idea: Determines if a target matrix can be obtained by rotating an input matrix by 0, 90, 180, or 270 degrees clockwise.
 * Time Complexity: O(N^2), where N is the dimension of the square matrix.
 * Space Complexity: O(1).
 */
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n=mat.size()-1;
        bool a=true,b=true,c=true,d=true;

        for(int i =0;i<=n;i++)
            for(int j=0;j<=n;j++)
                {
                    if (target[i][j]!=mat[i][j]) a=false;
                    if (target[i][j]!=mat[n-i][n-j]) b=false;
                    if (target[i][j]!=mat[j][n-i]) c=false;
                    if (target[i][j]!=mat[n-j][i]) d=false;
                }

        if (a || b || c || d) return true;
   
        return false;
    }
};
```