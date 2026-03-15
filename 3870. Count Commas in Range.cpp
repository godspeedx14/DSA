```cpp
// Core idea: This function calculates a value based on the input integer 'n'. If 'n' is less than or equal to 999, it returns 0. Otherwise, it returns the difference between 'n' and 999.
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int countCommas(int n) {
        if (n>999) return n-999;
        return 0;
    }
};
```