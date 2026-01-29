```cpp
/*
 * Core Idea: This function rotates only the non-negative elements of the input array `nums` by `k` positions.
 * It first extracts the indices and values of all non-negative elements. Then, it cyclically shifts these
 * extracted values by `k` positions and places them back into their original positions in the `nums` array.
 * Negative elements retain their original positions and values.
 *
 * Time Complexity: O(n), where n is the size of the input vector `nums`.
 *                  This is due to two passes over the elements (one to extract, one to place back).
 * Space Complexity: O(n), where n is the size of the input vector `nums`.
 *                   This is due to storing auxiliary vectors `pos` and `val`, which can grow up to size `n`.
 */
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>pos;
        vector<int>val;
        int n=nums.size();

        for(int i=0;i<n;i++)
            if (nums[i]>=0)
            {pos.push_back(i);val.push_back(nums[i]);}

        int m=pos.size();
        for(int j=0;j<m;j++)
            {
                int x=(j+k)%m;
                nums[pos[j]]=val[x];
            }

        return nums;
    }
};

//     0
```
