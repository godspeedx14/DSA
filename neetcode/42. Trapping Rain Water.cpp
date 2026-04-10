class Solution {
public:
    int trap(vector<int>& h) {
        int mx=0,n=h.size()-1;
        vector<int>prev;
        for(int i =n;i>=0;i--)
        {
             prev.push_back(mx);
             mx=max(mx,h[i]);
        }
       
        mx=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
 
            if (h[i]>mx) {mx=h[i];continue;}
 
            if(min(mx,prev[n-i])>h[i]) sum+=min(mx,prev[n-i])-h[i];
        }
 
     return sum;
    }
};