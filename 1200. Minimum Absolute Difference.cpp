```cpp
/*
 * Core Idea:
 * Sort the array to ensure minimum absolute differences occur between adjacent elements.
 * Iterate through the sorted array, tracking the smallest difference found.
 * Collect all pairs that exhibit this minimum absolute difference.
 *
 * Time Complexity: O(N log N)
 * Dominated by sorting the array. Subsequent iteration is O(N).
 *
 * Space Complexity: O(N)
 * O(N) for storing the result pairs in the worst case (e.g., all adjacent pairs have the minimum difference).
 * Sorting might also use O(log N) to O(N) auxiliary space depending on the implementation.
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