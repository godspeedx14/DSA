```cpp
/*
Core Idea:
Finds the maximum total value from at most two non-overlapping events. It iterates through events sorted by their start times. For each event (considered as the second event), it efficiently finds the maximum value of a preceding, non-overlapping event (the first event) using a separate list sorted by end times and a two-pointer approach. It also handles the case of selecting only one event.

Time Complexity: O(N log N)
  - Dominated by sorting operations for events.
  - The main loop with the inner two-pointer scan contributes O(N).

Space Complexity: O(N)
  - For storing a copy of the events vector.
*/
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        int n= v.size(),mx=0,etmax=0,et=0;
        
        
        //sorting on end time
        sort(v.begin(),v.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});
        vector<vector<int>>v1=v;
        

        //sorting on start time
        sort(v.begin(),v.end()); 

        int j=0;
        for(auto& i:v)
        {   
            int st=i[0],val=i[2];
            mx=max(mx,val);
            if (et<st)
            {
                et=st;
                while (j<n && v1[j][1]<st)
                {
                    etmax=max(etmax,v1[j][2]);
                    j++;
                }
            }
            mx=max(mx,etmax+val);
        }
        
        return mx;
    }
};
```