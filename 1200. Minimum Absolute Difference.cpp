```cpp
// Core Idea: Sorts the array and then iterates through the sorted array to find the minimum absolute difference between adjacent elements, collecting all such pairs.
// Time Complexity: O(N log N) due to sorting, where N is the number of elements in the array.
// Space Complexity: O(N) to store the result pairs in the worst case.
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