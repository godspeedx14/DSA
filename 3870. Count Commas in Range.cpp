```cpp
class Solution {
public:
    /*
     * Core Idea: Counts integers from 1000 to n (inclusive) if n > 999; returns 0 otherwise.
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int countCommas(int n) {
        if (n>999) return n-999;
        return 0;
    }
};
```