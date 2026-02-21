```cpp
/*
Core idea: This solution identifies the first number in the input array whose frequency (count of occurrences) is unique across all distinct frequencies present in the array.
It achieves this by:
1.  Counting the occurrences of each number.
2.  Then, counting how many *numbers* share each specific frequency count.
3.  Finally, iterating through the original array to return the first number whose frequency count has a count of 1 in the second frequency map.

Time Complexity: O(N) on average, where N is the number of elements in `nums`.
This involves three passes: one over the input array, one over the unique elements' frequencies, and one final pass over the input array. Each operation with `unordered_map` is O(1) on average.

Space Complexity: O(N) on average, where N is the number of elements in `nums`.
Two `unordered_map`s are used: one to store frequencies of numbers (up to N distinct numbers) and another to store frequencies of frequencies (up to N distinct frequency counts).
*/
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int i:nums)
            freq[i]++;

        unordered_map<int,int>fr1;

        for(auto it:freq)
            fr1[it.second]++;

        for (int i:nums)
            if (fr1[freq[i]]==1) return i;

        return -1;
    }
};
```