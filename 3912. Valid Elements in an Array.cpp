class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>x;
        int n=nums.size();
        int rg=0;
        for (int i=n-1;i>=0;i--)
            {
                x.push_back(rg);
                rg=max(rg,nums[i]);
            }

        int lg=0;
        vector<int>res;
        for(int i=0;i<n;i++)
            {
                if (nums[i]>lg || nums[i]>x[n-1-i])
                    res.push_back(nums[i]);
                lg=max(lg,nums[i]);
            }

        return res;
    }
};