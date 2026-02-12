```cpp
// Core idea: Sorts the array. Then, iterates through the sorted array to find the
// smallest absolute difference between any adjacent pair. All pairs that
// exhibit this minimum difference are collected into the result.
// Time complexity: O(N log N) due to the initial sorting step, where N is the number of elements in the array.
// Space complexity: O(N) in the worst case for storing the result pairs, where N is the number of elements.
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