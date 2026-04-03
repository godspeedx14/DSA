```cpp
/*
 * Core Idea:
 * This function calculates the total number of commas needed to format all integers from 1 to 'n'
 * (inclusive) using standard comma separators (e.g., 1,000; 1,000,000). It works by summing the
 * count of numbers that introduce a comma at each magnitude level. Specifically, for each power
 * of 1000 (10^3, 10^6, etc.), it adds the number of integers from that power up to 'n' to the
 * total, effectively counting each comma position across all relevant numbers.
 *
 * Time Complexity: O(log_1000(n))
 * The while loop multiplies 'beg' by 1000 in each iteration. For a 'long long' input 'n' (up to ~10^18),
 * this results in a very small, constant number of iterations (approximately 6-7).
 *
 * Space Complexity: O(1)
 * The function uses a fixed number of local variables, independent of the input size 'n'.
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