class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mx,mn;

        int n=nums.size();
        int mxr=nums[0],mnr=nums[n-1];
        for (int i =0;i<n;i++)
            {
                mxr=max(mxr,nums[i]);
                mx.push_back(mxr);
            }
        for(int i=n-1;i>=0;i--)
            {
                mnr=min(mnr,nums[i]);
                mn.push_back(mnr);
            }

        int res=INT_MAX;

        for(int i=0;i<n;i++)
            {
                int x=mx[i]-mn[n-1-i];
                if(x<=k)
                    return i;
            }
        return -1;
    }
};