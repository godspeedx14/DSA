```cpp
/*
 * Core Idea: Finds all pairs of elements with the minimum absolute difference.
 *            The algorithm sorts the array first, then iterates through adjacent
 *            elements to determine the minimum difference and collect all
 *            pairs that achieve this minimum.
 *
 * Time Complexity: O(N log N) primarily due to the sorting step. The subsequent linear scan is O(N).
 * Space Complexity: O(N) to store the resulting pairs in the worst case, plus O(log N) for sort's auxiliary space.
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