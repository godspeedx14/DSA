```cpp
// Core idea: This algorithm finds all pairs of elements in the input array that have the minimum absolute difference.
// It first sorts the array, as the minimum difference must occur between adjacent elements in a sorted array.
// Then, it iterates through the sorted array, maintaining the smallest difference found and collecting all pairs that exhibit this minimum difference.
// Time complexity: O(N log N), primarily due to the sorting step.
// Space complexity: O(N) to store the result pairs, where N is the number of elements in the array.
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