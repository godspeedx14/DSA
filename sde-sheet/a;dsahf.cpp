```cpp
// Core idea: Calculates the minimum number of operations (flips) to transform the binary string into an alternating pattern (either '0101...' or '1010...'). It counts flips required for one pattern and infers the other.
// Time complexity: O(n), where n is the length of the string.
// Space complexity: O(1).
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
            {
                if ((s[i]^i)&1)
                {
                    cnt++;
                }
            }

        return min(cnt,n-cnt);
    }
};
```