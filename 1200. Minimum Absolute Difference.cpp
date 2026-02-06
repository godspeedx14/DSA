```cpp
/*
 * Core idea:
 * This algorithm identifies all pairs of elements within the input array that possess
 * the minimum absolute difference. It first sorts the array, which is crucial because
 * the minimum absolute difference will then always occur between adjacent elements.
 * Subsequently, it iterates through the sorted array, maintaining the smallest
 * difference encountered and collecting all pairs that match this minimum difference.
 *
 * Time complexity:
 * O(N log N), dominated by the initial sorting of the array. The subsequent linear
 * scan takes O(N) time.
 *
 * Space complexity:
 * O(N), primarily for storing the result pairs. In the worst case, nearly all
 * adjacent pairs might share the minimum absolute difference. Auxiliary space for
 * the sort operation itself is typically O(log N) for `std::sort`.
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