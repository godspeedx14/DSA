```cpp
// Core idea: Determines if two 4-character strings can be made identical by independently
// swapping characters at indices (0, 2) and (1, 3). This is achieved by checking
// if the character pair at (0, 2) in s1 matches the pair in s2 (order-agnostic),
// and similarly for the pair at (1, 3).
// Time complexity: O(1) - Constant time due to a fixed number of comparisons.
// Space complexity: O(1) - Constant space for a few boolean variables.
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool b1=false ,b2=false;
        if ((s1[0]==s2[0] && s1[2]==s2[2]) || (s1[0]==s2[2] && s1[2]==s2[0]))
        b1= true;

        if ((s1[1]==s2[1] && s1[3]==s2[3]) || (s1[1]==s2[3] && s1[3]==s2[1]))
        b2=true;

        return b1 && b2;
    }
};
```