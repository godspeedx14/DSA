```cpp
/*
 * Core idea: This function calculates a value based on the input integer 'n'.
 *            If 'n' is greater than 999, it returns the difference 'n - 999';
 *            otherwise, it returns 0.
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
class Solution {
public:
    int countCommas(int n) {
        if (n>999) return n-999;
        return 0;
    }
};
```