```cpp
/**
 * Core Idea: Uses a two-pointer approach to find an index where the sum of elements to its left equals the product of elements to its right.
 *            Pointers `i` (for left sum `l`) and `j` (for right product `r`) move inwards, iteratively expanding the side with the smaller accumulated value
 *            (sum or product) to maintain balance. If `l` and `r` are equal when `i` and `j` meet, `i` is returned; otherwise, -1.
 * Time Complexity: O(N), where N is the number of elements in `nums`. The two pointers traverse the array at most once.
 * Space Complexity: O(1), as only a constant amount of extra space is used.
 */
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
       long long l=0,r=1;
        int i=0,j=nums.size()-1;
        
        while(i<j)
            {
                if (l<r) l+=nums[i],i++;
                else r*=nums[j],j--;
            }
        return i==j && l==r ?i:-1;
           
    }
};

```