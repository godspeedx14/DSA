```cpp
/*
 * Core Idea:
 * The `big` function implements a custom bit manipulation logic to transform an integer `x`.
 * - If `x` is 2, it returns -1.
 * - If `x` consists solely of `1`s in its binary representation (e.g., 1, 3, 7, which are `2^k - 1`), it clears its most significant bit.
 * - Otherwise, it identifies the first `0` bit encountered when traversing from the least significant bit (LSB) upwards. If this `0` bit is preceded by at least one `1` bit, it clears the bit immediately preceding this first `0` bit. If the LSB itself is `0`, this specific modification has no effect.
 * The `minBitwiseArray` function applies this `big` transformation to each element of the input vector.
 *
 * Time Complexity:
 *   - `big(int x)`: O(log x), as it iterates through the bits of `x`. The `pow` function for small integer exponents can be considered O(1).
 *   - `minBitwiseArray(vector<int>& nums)`: O(N * log(max_val)), where `N` is the size of `nums` and `max_val` is the maximum integer value in `nums`.
 * Space Complexity:
 *   - `big(int x)`: O(1)
 *   - `minBitwiseArray(vector<int>& nums)`: O(N) for storing the result vector.
 */
class Solution {
public:
    int big(int x)
    {
        int rem=x;
        if (x==2) return -1;
        int res=0,p=0,flg=true;
        while (x)
        {
            int d=x%2;
            x/=2;

            if (flg && d==0)
            {
                flg=false;
                res-=pow(2,p-1);

            }

            res+=pow(2,p)*d;
            
            p++;
        }
        if (flg) res-=pow(2,(p-1));
        return res;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> x;

        for(int a:nums)
            {
                x.push_back(big(a));
            }
        
        return x;
    }
};
```