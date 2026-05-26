```cpp
/*
 * Core Idea: Filters the input array to limit consecutive occurrences of any number to 'k'.
 *            The algorithm iterates through the array, building a result list. An element is
 *            added if it's either different from the last added element, or if it's the same
 *            but its consecutive count has not yet reached 'k'.
 *
 * Time Complexity: O(N), where N is the number of elements in the input vector 'nums'.
 *                  The algorithm performs a single pass through the input array.
 * Space Complexity: O(N), where N is the number of elements in the input vector 'nums'.
 *                   In the worst case (e.g., 'k' is very large or all elements are distinct),
 *                   the resulting vector 'res' could contain up to N elements.
 */
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>res;
        int n= nums.size();
        int c=0,cn=-1;
        for (int i=0;i<n;i++)
            if(nums[i]==cn && c<k)
                {res.push_back(nums[i]);
                c++;}
            else if( nums[i]!=cn)
                {res.push_back(nums[i]);
                c=1,cn=nums[i];}

        return res;
    }
};
```