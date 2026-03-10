```cpp
/*
 * Core Idea: Generates Pascal's Triangle row by row. Each row starts and ends with 1,
 * with intermediate elements calculated by summing adjacent elements from the previous row.
 *
 * Time Complexity: O(numRows^2)
 *   - The outer loop runs `numRows` times.
 *   - Inside the loop, creating the row and calculating its elements takes O(i) time for row `i`.
 *   - The total time complexity is the sum of `i` from 0 to `numRows-1`, resulting in O(numRows^2).
 *
 * Space Complexity: O(numRows^2)
 *   - The algorithm stores all generated rows in the `res` vector.
 *   - The total number of elements in Pascal's Triangle up to `numRows` is proportional to `numRows^2`.
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