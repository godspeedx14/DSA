/*
Core Idea: Counts subarrays where the sum of elements equals one of its own elements.
Time Complexity: O(N^2) on average due to nested loops and O(1) average hash map operations. Worst case O(N^3) if hash collisions are frequent.
Space Complexity: O(N) for the hash map storing elements of the current subarray.
*/
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        
        int n=nums.size(),res=0;
        
        for(int i =0;i<n;i++)
            {
                unordered_map<int,bool>mp;
                long long sum=0;
                for(int j=i;j<n;j++)
                    {
                    mp[nums[j]]=true;
                     sum+=nums[j];
                     if (mp.count(sum)) res++;
                    }
            
            }
        return res;
    }
};