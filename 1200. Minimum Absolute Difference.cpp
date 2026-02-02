```cpp
// Core idea: Sort the array to ensure minimum absolute differences are between adjacent elements.
// Then, iterate through the sorted array to find the smallest difference and collect all pairs that exhibit this minimum difference.
// Time complexity: O(N log N) due to sorting, where N is the number of elements in the array.
// Space complexity: O(N) to store the result pairs, as in the worst case, all adjacent pairs could have the minimum difference.
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