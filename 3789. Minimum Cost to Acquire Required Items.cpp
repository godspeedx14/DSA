```cpp
// Core Idea:
// Calculates the minimum cost to acquire n1 items of type 1 and n2 items of type 2, given individual costs (c1, c2) and a bundle cost (cb).
// The logic considers purchasing items individually, purchasing a common quantity via the bundle cost and remaining items individually,
// and a special case where a very cheap bundle cost (cb <= c1 or cb <= c2) leads to applying the bundle cost to the maximum required quantity.
//
// Time Complexity: O(1)
// The function performs a constant number of arithmetic operations and comparisons.
//
// Space Complexity: O(1)
// The function uses a fixed amount of memory for variables.
class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        
        if (cb>=(c1+c2))
            return 1ll*c1*n1+1ll*c2*n2;

        long long x=cb;
        if (n1<n2)
        {
            if (cb<=c2) return x*n2;
            int ext= n2-n1;
            return x*n1 + 1ll*ext*c2;
        }
        if (n1>n2)
        {
            if (cb<=c1) return x*n1;
            int ext= n1-n2;
            return x*n2 + 1ll*ext*c1;
        }

        return 1ll*cb*n1;
            
    }
};
```