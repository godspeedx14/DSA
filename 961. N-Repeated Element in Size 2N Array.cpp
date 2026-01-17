```cpp
class Solution {
public:
// Core Idea: Uses a hash map to track encountered numbers. The first number found that is already in the map is the repeated element.
// Time Complexity: O(N) on average, where N is the number of elements in the input vector, due to average O(1) hash map operations.
// Space Complexity: O(N) in the worst case, to store distinct elements in the hash map.
#define godspeed unordered_map

    int repeatedNTimes(vector<int>& nums) {
        godspeed <int,bool> mp;

        for (auto& i:nums)
            {if (mp.count(i)) return i;mp[i]=true;}

            return -1;

    }
};
```