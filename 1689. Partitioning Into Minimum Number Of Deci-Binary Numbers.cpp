```cpp
/*
 * Core idea: The minimum number of partitions required is equal to the largest digit present in the input string.
 * Time complexity: O(L), where L is the length of the input string n.
 * Space complexity: O(1).
 */
class Solution {
public:
    int minPartitions(string n) {
        char i='1';
        for (char c:n)
            i=max(i,c);
        return i-'0';
    }
};
```