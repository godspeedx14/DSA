class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0],ans=0;

        for(int i:prices)
        {
            mn=min(mn,i);
            ans=max(ans,i-mn);
        }
        return ans;
    }
};