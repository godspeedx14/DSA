```cpp
/*
 * Core idea:
 * For each number in the input array, calculate its greatest common divisor (GCD) with the running maximum seen so far.
 * Store these calculated GCDs in a list, then sort this list.
 * Finally, sum the GCDs of pairs formed by taking elements from the beginning and end of the sorted list.
 *
 * Time complexity: O(N log N + N log M), where N is the number of elements in 'nums' and M is the maximum value in 'nums'.
 *                  This accounts for N GCD calculations (each O(log M)) and sorting N elements (O(N log N)).
 * Space complexity: O(N) for storing the intermediate GCD values in 'gcdv'.
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