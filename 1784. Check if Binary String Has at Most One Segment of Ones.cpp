```cpp
/**
 * Core idea: Checks if all '1's in the binary string form a single contiguous segment.
 *            It iterates to find the end of the initial '1's segment, then verifies no '1's exist afterwards.
 * Time complexity: O(n), where n is the length of the string s, due to a single pass.
 * Space complexity: O(1), as only a few constant-space variables are used.
 */
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0,n=s.size();
        while(i<n && s[i]=='1')
            {i++;}
        for(;i<n;i++)
            if(s[i]=='1') return false;
        return true;
    }
};
```