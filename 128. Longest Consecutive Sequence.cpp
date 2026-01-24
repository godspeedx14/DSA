```cpp
/*
 * Core Idea:
 * - Store all numbers in a hash set for efficient O(1) average-time lookups.
 * - Iterate through each number in the set. For each number, check if it's the potential
 *   start of a sequence (i.e., 'num - 1' is not present in the set).
 * - If it's a start, find the length of the consecutive sequence by repeatedly checking
 *   for 'num + 1', 'num + 2', etc., in the set.
 * - Track and update the maximum sequence length found. This approach ensures each number
 *   is processed efficiently, often only once as a sequence start or part of an ongoing sequence.
 *
 * Time Complexity: O(N) on average, where N is the number of elements in nums.
 * - O(N) to insert all elements into the hash set.
 * - O(N) for iterating through the set and finding consecutive sequences. Although there's
 *   a nested loop, each number is checked for its predecessor at most once and visited
 *   as part of a sequence at most once, leading to an overall linear time complexity.
 *
 * Space Complexity: O(N) where N is the number of unique elements in nums.
 * - O(N) to store all unique numbers in the hash set.
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int res=0,cur=1;

        for(int i:st)
            {
                if (!st.count(i-1))
                    {while(st.count(i+1)) cur++,i++;
                    res=max(res,cur);
                    cur=1;
                    }

            }
        return res;
    }
};
```