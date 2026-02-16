```cpp
// Core idea: Sort the array to ensure that the minimum absolute difference between any two elements will always be between adjacent elements. Iterate through the sorted array to find this minimum difference and collect all pairs that achieve it.
// Time complexity: O(N log N) due to the sorting step, where N is the number of elements in the input array.
// Space complexity: O(N) for storing the resulting pairs, as in the worst case, nearly all adjacent pairs could have the minimum absolute difference.
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