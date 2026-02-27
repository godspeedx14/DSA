```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        /*
         * Core Idea: Find all pairs with the minimum absolute difference.
         * The minimum absolute difference between any two elements in an array
         * will always be found between adjacent elements once the array is sorted.
         * The algorithm sorts the array, then iterates to find the smallest
         * difference, collecting all pairs that exhibit this minimum difference.
         *
         * Time Complexity: O(N log N) due to the initial sorting step, where N is the array size.
         * Space Complexity: O(N) to store the result pairs in the worst case (e.g., all adjacent pairs have the same minimum difference).
         */
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