```cpp
/*
 * Core Idea: Finds all pairs of elements with the minimum absolute difference. This is achieved by first sorting the array,
 *            then iterating through adjacent elements to identify the smallest difference and collect all pairs that exhibit it.
 * Time Complexity: O(N log N), dominated by the initial sorting of the array.
 * Space Complexity: O(N), for storing the resulting pairs in the worst-case scenario.
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        int n=arr.size(),dif=arr[1]-arr[0];
        int cur;
        for(int i=1;i<n;i++)
        {   
            cur=arr[i]-arr[i-1];
            if(cur<dif) {res=vector<vector<int>> {};dif=cur;}
            if (cur==dif) res.push_back(vector<int>{arr[i-1],arr[i]});
        }
        return res;
    }
};
```