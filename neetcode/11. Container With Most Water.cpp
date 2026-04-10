/*
 * Core idea: Use a two-pointer approach. Start with pointers at both ends. In each step, calculate the area and move the pointer corresponding to the shorter line inward. This strategy ensures we are always trying to find a potentially larger height to compensate for decreasing width.
 * Time complexity: O(N), where N is the number of lines (height.size()), as each pointer traverses the array once.
 * Space complexity: O(1), as only a few constant extra variables are used.
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,mx=0;

        while(l<r)
        {
            mx=max(mx,(r-l)*min(height[l],height[r]));
            if (height[l]<height[r])l++;
            else r--;
        }

        return mx;
    }
};
