```cpp
class Solution {
public:
    // Core idea: Checks if the absolute difference between ASCII values of any two adjacent characters in the string is at most 2.
    // Time complexity: O(n), where n is the length of the input string.
    // Space complexity: O(1).
    bool isAdjacentDiffAtMostTwo(string s) {
        int n= s.size();

        for (int i=0;i<n-1;i++)
            if(abs(s[i]-s[i+1])>2) return false;

        return true;
    }
};
```