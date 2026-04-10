class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>v;
        for (int i =0;i<n-2;i++)
        {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int t=-nums[i];
            int j=i+1,k=n-1;
            while (j<k)
            {if (nums[j]+nums[k]==t) {v.push_back({nums[i],nums[j],nums[k]});j++;while(j<k && nums[j-1]==nums[j]) j++;}
            if (nums[j]+nums[k]<t) j++;
            else k--;}
        }
        return v;
    }
};