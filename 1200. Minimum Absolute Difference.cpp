```cpp
// Core Idea:
// The algorithm finds all pairs of elements with the minimum absolute difference.
// It first sorts the array, as the minimum difference must occur between adjacent elements in a sorted array.
// Then, it iterates through the sorted array, tracking the current minimum difference and collecting all pairs that exhibit this difference.

// Time Complexity: O(N log N)
// Dominated by the initial sorting of the input array. The subsequent single pass through the array takes O(N) time.

// Space Complexity: O(N)
// Primarily for storing the result vector, which in the worst case can hold up to N-1 pairs.
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