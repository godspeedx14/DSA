```cpp
class Solution {
public:
    // Core idea: Determines if the target matrix can be formed by rotating the input matrix 'mat' by 0, 90, 180, or 270 degrees clockwise.
    // It simultaneously compares the target matrix against 'mat' in all four possible orientations.
    // Time complexity: O(N^2), where N is the dimension of the square matrix.
    // Space complexity: O(1).
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n=mat.size()-1;
        bool a=true,b=true,c=true,d=true;

        for(int i =0;i<=n;i++)
            for(int j=0;j<=n;j++)
                {
                    if (target[i][j]!=mat[i][j]) a=false;
                    if (target[i][j]!=mat[n-i][n-j]) b=false;
                    if (target[i][j]!=mat[j][n-i]) c=false;
                    if (target[n-j][i]!=target[i][j]) d=false;
                }

        if (a || b || c || d) return true;
   
        return false;
    }
};
```