```cpp
/*
 * Core Idea: Implements the "next permutation" algorithm.
 * It finds the lexicographically next greater permutation of numbers.
 * The algorithm works by finding the first pair (nums[i-1], nums[i]) from the right
 * such that nums[i-1] < nums[i]. It then sorts the suffix from index i to the end
 * in ascending order, finds the smallest element in this suffix greater than nums[i-1],
 * and swaps it with nums[i-1]. If no such pair is found, the array is reversed
 * to become the lowest possible order (ascending).
 *
 * Time Complexity: O(N log N) in the worst case due to the `std::sort` operation on a suffix of the array.
 * Space Complexity: O(log N) due to the recursive stack space used by `std::sort`.
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;

        for (int i =n;i>0;i--)
            if (nums[i]>nums[i-1]) {
                sort(nums.begin()+i,nums.end());
                int j=i;
                while(nums[j]<=nums[i-1])
                    j++;
                swap(nums[i-1],nums[j]);
                return;}
        sort(nums.begin(),nums.end());
    }
};
```