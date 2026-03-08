```cpp
/*
 * Core Idea: Finds the index of the smallest capacity that is greater than or equal to `itemSize`.
 *            Returns -1 if no suitable capacity is found.
 * Time Complexity: O(n), where n is the number of elements in the `capacity` vector, due to a single pass.
 * Space Complexity: O(1), as only a few constant extra variables are used.
 */
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int sm=INT_MAX,si=-1,n=capacity.size();

        for(int i=0;i<n;i++)
            {
                if (capacity[i]<sm && capacity[i]>=itemSize) si=i,sm=capacity[i];
            }

        return si;
    }
};
```