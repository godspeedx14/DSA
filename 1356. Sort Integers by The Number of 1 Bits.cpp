```cpp
/*
 * Core idea: Sorts integers based on their number of set bits (popcount) in ascending order.
 *            If two numbers have the same popcount, they are sorted by their numerical value in ascending order.
 *            This is achieved by grouping numbers by their popcount using a map, sorting each group numerically,
 *            and then concatenating the sorted groups based on ascending popcount.
 * Time complexity: O(N * (log M + log N)), where N is the number of elements in the input array,
 *                  and M is the maximum value in the array.
 *                  Specifically, calculating popcounts for all N numbers contributes O(N log M).
 *                  Sorting numbers within each popcount group contributes O(N log N) in total.
 * Space complexity: O(N) for storing the map and the result vector.
 */
class Solution {
public:

    int cnt1(int x)
    {
        int res=0;
        while(x)
            res+=x%2,x/=2;
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i:arr)
            {
                mp[cnt1(i)].push_back(i);
            }
        
        vector<int>res;
        for(auto it:mp)
            {sort(it.second.begin(),it.second.end());
                for(auto j:it.second)
                res.push_back(j);}

        return res;
    }
};
```