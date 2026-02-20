```cpp
// Core Idea: Sort the array and iterate through adjacent elements to find the minimum absolute difference.
//            Collect all pairs that exhibit this minimum difference.
// Time Complexity: O(N log N) due to sorting, where N is the number of elements in the array.
// Space Complexity: O(N) for storing the result pairs, where N is the number of elements in the array.
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