```cpp
/**
 * Core Idea:
 * The problem segments houses into contiguous blocks of identical colors. Houses of different colors are independent, meaning picking a house of one color does not affect decisions for houses of another color. Within each color block, the classic "House Robber" problem is applied: maximize the sum of chosen house values such that no two chosen houses are adjacent. The final result is the sum of maximum values obtained from each color block.
 *
 * Time Complexity:
 * O(N), where N is the number of houses. The algorithm iterates through the houses once to identify color blocks. For each color block, a dynamic programming solution (House Robber) is applied. Since each house belongs to exactly one color block, the total work done by the dynamic programming across all blocks sums up to O(N).
 *
 * Space Complexity:
 * O(N), where N is the number of houses. This is primarily due to the memoization `dp` array used by the `f` function. In the worst case (all houses have the same color), this `dp` array will be of size N. Additionally, the recursion stack for `f` can go up to O(N) in depth.
 */
class Solution {
public:

    long long f (int ind, int i,vector<int> &nums,vector<long long>& dp){
        if (ind < i) return 0;
        if(dp[ind-i]!= -1) return dp[ind-i];

        long long pick = nums[ind] +f(ind-2,i,nums, dp);
        long long notPick = 0 +f(ind-1,i,nums,dp);

        return dp[ind-i]=max(pick,notPick);
    }
    long long mx(vector<int> &nums,int i,int j)
    {
        int n=j-i;

        vector<long long> dp(n,-1);
        return f(j-1,i,nums,dp);
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long res=0;

        int n=nums.size();

        for(int i=0;i<n;i++)
            {
                int j=i+1;
                while (j<n && colors[j]==colors[i])
                    {
                        j++;
                    }
                res+=mx(nums,i,j);
                i=j-1;
            }
        return res;
    }
};
```