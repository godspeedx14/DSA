```cpp
/*
 * Core Idea: Concatenates the input vector with its reversed version.
 * Time Complexity: O(N), where N is the number of elements in the input vector.
 * Space Complexity: O(N), for storing the resulting concatenated vector.
 */
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans=nums;

        int n=nums.size();
        for(int i=n-1;i>=0;i--)
            ans.push_back(nums[i]);

        return ans;
    }
};
```