```cpp
// Core Idea: This function identifies the longest strictly increasing suffix of the input array `nums`.
// It then returns the length of the prefix that must be retained such that the remaining suffix is strictly increasing.
// Time Complexity: O(N), where N is the number of elements in `nums`, as it performs a single pass through the array.
// Space Complexity: O(1), as it uses a constant amount of extra space regardless of input size.
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int cnt=1,n = nums.size();
        for (int i=n-1;i>0;i--)
            {
                if (nums[i]>nums[i-1]) cnt++;
                else break;
            }
        return n-cnt;
    }
};
```