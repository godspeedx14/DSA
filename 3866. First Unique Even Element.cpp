```cpp
/*
 * Core Idea: Finds the first even number in the array that appears exactly once.
 *            It first builds a frequency map for all numbers, then iterates through
 *            the array again to find the first element that is even and has a count of one.
 *
 * Time Complexity: O(N) on average, where N is the number of elements in 'nums'.
 *                  This involves two passes over the array, each performing O(1) average time
 *                  hash map operations (insertions/lookups).
 *
 * Space Complexity: O(N) in the worst case, where N is the number of elements in 'nums'.
 *                   The hash map stores up to N distinct elements and their frequencies.
 */
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (auto i:nums)
            mp[i]++;
        for (auto i:nums)
            if (i%2==0 && mp[i]==1)
                return i;

        return -1;
    }
};
```