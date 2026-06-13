```cpp
/*
 * Core Idea: Filters elements from the input array, retaining them only if their
 *            consecutive count does not exceed 'k'. A number differing from the
 *            previous one always resets the consecutive count.
 * Time Complexity: O(N), where N is the number of elements in 'nums'.
 * Space Complexity: O(N) for storing the result vector.
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