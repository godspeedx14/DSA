```cpp
/*
 * Core Idea:
 * To find all pairs with the minimum absolute difference, first sort the array.
 * The minimum difference must exist between adjacent elements in a sorted array.
 * Iterate through the sorted array, tracking the minimum difference found and collecting all pairs that match it.
 *
 * Time Complexity: O(N log N)
 * Sorting the array dominates the time complexity. The subsequent linear scan takes O(N).
 *
 * Space Complexity: O(N)
 * Stores up to N-1 pairs in the result vector.
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