```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        /*
         * Core Idea: Calculates the minimum time to visit all points in order by summing the Chebyshev distance (maximum of absolute differences in coordinates) between each adjacent pair of points.
         * Time Complexity: O(N), where N is the number of points. The algorithm iterates through the points once.
         * Space Complexity: O(1). Only a few constant-size variables are used.
         */
        int n=points.size(),res=0;
        for (int i=0;i<n-1;i++)
            {
                res+=max(abs(points[i][0]-points[i+1][0]),abs(points[i][1]-points[i+1][1]));
            }
        return res;
    }
};
```