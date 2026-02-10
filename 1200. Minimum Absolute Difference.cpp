```cpp
/*
 * Core Idea: The algorithm sorts the array to ensure minimum absolute differences are between adjacent elements.
 * It then iterates through the sorted array to find the smallest difference and collects all pairs that achieve it.
 * Time Complexity: O(N log N) due to the sorting step, where N is the number of elements in the array.
 * Space Complexity: O(N) in the worst case for storing the result pairs.
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