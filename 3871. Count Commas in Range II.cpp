```cpp
/*
 * Core Idea: Calculates the total number of thousands-separator commas required when formatting all integers from 1 to n.
 * Time Complexity: O(log N) due to the loop iteratively multiplying 'beg' by 1000.
 * Space Complexity: O(1) as it uses a fixed number of variables regardless of input size.
 */
class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        long long beg=1000;

        while(beg<=n)
            {
                res+=n-(beg-1);
                beg*=1000;
            }
        return res;
    }
};
```