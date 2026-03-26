```cpp
// Core idea: Constructs Pascal's Triangle row by row. Each row starts and ends with 1, and intermediate elements are the sum of the two elements directly above them from the previous row.
// Time complexity: O(numRows^2) - Each row's elements are computed iteratively, leading to a quadratic number of operations relative to numRows.
// Space complexity: O(numRows^2) - Stores all elements of the generated Pascal's Triangle.
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