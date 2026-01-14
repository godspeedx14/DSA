```cpp
/*
 * Core Idea: Determines the length of the smallest repunit (a number consisting only of '1's)
 * that is a multiple of `k`. The algorithm iteratively computes repunits modulo `k`,
 * efficiently finding the first instance where a repunit is divisible by `k`.
 * It includes an initial check for `k` divisible by 2 or 5, as no solution exists in these cases.
 *
 * Time Complexity: O(k)
 * The loop iterates at most `k` times, as there are `k` possible distinct remainders modulo `k`.
 *
 * Space Complexity: O(1)
 * The algorithm uses a constant number of auxiliary variables.
 */
class Solution {
public:
    int minAllOneMultiple(int k) {
        // the only number that return -1 are-
        if (k%2==0 || k%5==0) return -1;

        int cnt=1,n=1;

        while (true)
        {
            n%=k;
            if (!n) return cnt;
            n=n*10+1;
            cnt++;
        }
    }
};
```