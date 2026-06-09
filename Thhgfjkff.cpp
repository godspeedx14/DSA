```cpp
/*
 * Core Idea:
 * Precomputes prefix maximums and suffix minimums for the input array.
 * It then iterates through each possible split point 'i' to find the first index
 * where the maximum value in the prefix (nums[0...i]) minus the minimum value in the suffix (nums[i...n-1])
 * is less than or equal to 'k'.
 *
 * Time Complexity: O(n)
 * - Three linear passes over the array: one for prefix maximums, one for suffix minimums, and one for checking the condition.
 *
 * Space Complexity: O(n)
 * - Two auxiliary arrays of size 'n' are used to store prefix maximums and suffix minimums.
 */
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mx,mn;

        int n=nums.size();
        int mxr=nums[0],mnr=nums[n-1];
        for (int i =0;i<n;i++)
            {
                mxr=max(mxr,nums[i]);
                mx.push_back(mxr);
            }
        for(int i=n-1;i>=0;i--)
            {
                mnr=min(mnr,nums[i]);
                mn.push_back(mnr);
            }

        int res=INT_MAX;

        for(int i=0;i<n;i++)
            {
                int x=mx[i]-mn[n-1-i];
                if(x<=k)
                    return i;
            }
        return -1;
    }
};
```