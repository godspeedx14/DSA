```cpp
/*
 * Core Idea: Counts elements `nums[i]` (iterating from right to left, excluding the last element) that are strictly greater than the average of the subarray `nums[i...n-1]`.
 * Time Complexity: O(n), where n is the number of elements in `nums`. The algorithm iterates through the array once.
 * Space Complexity: O(1). It uses a constant amount of extra space for variables.
 */
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[n-1],cnt=0;

        
        for (int i =n-2;i>=0;i--)
            {
                if(nums[i]>(sum/(n-1-i))) cnt++;
                sum+=nums[i];
            }
        return cnt;
    }
};
```