/*
 * Core Idea: Finds two numbers in a **sorted** array that sum to a target value using a two-pointer approach.
 *            Pointers start at both ends and move inwards based on the sum's comparison with the target.
 * Time Complexity: O(N), where N is the number of elements in the array.
 * Space Complexity: O(1).
 */

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, n=nums.size()-1;

        while (i<n)
        {
            if (nums[i]+nums[n]>target) n--;
            else if (nums[i]+nums[n]<target) i++;
            else return {i+1,n+1};
        }

        return {-1,-1};
        
    }
};
