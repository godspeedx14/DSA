```cpp
/*
 * Core Idea: Calculates the sum of elements for each row in the input matrix.
 *            Returns a vector where each element is the sum of the corresponding row.
 * Time Complexity: O(R * C), where R is the number of rows and C is the average number of columns.
 * Space Complexity: O(R), for storing the sums of R rows.
 */
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>res;
        int x=0;
        for (auto i:matrix)
            {for(int j:i)
                x+=j;
            res.push_back(x); x=0;}

        return res;
    }
};
```