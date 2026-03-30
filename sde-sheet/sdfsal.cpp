```c++
/*
 * Core idea: Find the first even number that appears exactly once in the array.
 *            Achieved by first counting all element frequencies using a hash map,
 *            then iterating through the array again to find the first element
 *            that is even and has a frequency of one.
 * Time complexity: O(N) on average, where N is the number of elements in 'nums'.
 *                  (Two passes over the array; hash map operations are O(1) on average).
 * Space complexity: O(D) where D is the number of distinct elements in 'nums'.
 *                   (Stores frequencies in a hash map). In the worst case, D can be N.
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