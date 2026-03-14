```cpp
/*
 * Core Idea:
 * This function processes an array `nums` to compute a specific sum.
 * It first constructs an intermediate vector `gcdv`. For each element `nums[k]`, `gcdv[k]` is calculated as the greatest common divisor (GCD) of `nums[k]` and the maximum value found within the prefix `nums[0...k]`.
 * Next, `gcdv` is sorted in ascending order.
 * Finally, the sum is computed by iterating approximately half the length of the sorted `gcdv`. In each iteration, it adds the GCD of an element from the beginning of `gcdv` (`gcdv[j]`) and its corresponding element from the end (`gcdv[size - 1 - j]`). If `gcdv` has an odd number of elements, the middle element is not included in the sum.
 *
 * Time Complexity: O(N log N + N log(M))
 *   - Building `gcdv`: N iterations, each involves a GCD calculation. A GCD of two numbers (up to M) takes O(log M). Total: O(N log M).
 *   - Sorting `gcdv`: O(N log N) using a comparison sort.
 *   - Summing GCDs: N/2 iterations, each involves a GCD calculation (O(log M)). Total: O(N log M).
 *   - Where N is the number of elements in `nums`, and M is the maximum possible value of an element in `nums`.
 *
 * Space Complexity: O(N)
 *   - For storing the `gcdv` vector, which holds N elements.
 */
class Solution {
public:

    long long gcd(long long a, long long b)
    {
    while(b){
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> gcdv;
        int mx=nums[0];
        for (int i:nums)
            {
                mx=max(mx,i);
                gcdv.push_back(gcd(mx,i));
            }
        sort(gcdv.begin(),gcdv.end());
        long long sum=0;
        int n=nums.size()-1;

        int x=(n+1)/2;
        for (int j=0;j<x;j++)
            sum+=gcd(gcdv[j],gcdv[n-j]);
        
        return sum;
    }
};
```