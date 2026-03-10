```cpp
/*
 * Core Idea: Generates Pascal's Triangle row by row. Each row is constructed by utilizing elements from the previous row;
 *            boundary elements are 1, and inner elements are the sum of the two elements directly above them.
 * Time Complexity: O(numRows^2) - Building each row `i` requires O(i) operations, resulting in a total sum of `O(i)` for `i` from `0` to `numRows-1`.
 * Space Complexity: O(numRows^2) - Stores the entire Pascal's Triangle, which contains `(numRows * (numRows + 1)) / 2` elements.
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for (int i =0;i<numRows;i++)
        {
            vector<int> v(i+1,1);
            for(int j=1;j<i;j++)
                    v[j]=res[i-1][j-1]+res[i-1][j];

            res.push_back(v);
        }

        return res;
    }
};
```