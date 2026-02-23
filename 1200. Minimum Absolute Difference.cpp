```cpp
// Core idea:
// - Sorts the input array to ensure that the minimum absolute difference will always be found between adjacent elements.
// - Iterates through the sorted array once to find the minimum difference and collect all pairs that exhibit this difference.
//
// Time complexity: O(N log N)
// - Dominated by the initial sorting of the array (std::sort).
// - The subsequent iteration to find differences and collect pairs takes O(N) time.
//
// Space complexity: O(N)
// - The result vector stores the pairs, which can contain up to N-1 pairs in the worst case (e.g., [1,2,3,4,5]).
// - std::sort typically uses O(log N) auxiliary space for its recursion stack (introsort).
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