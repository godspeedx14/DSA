```cpp
// Core idea: Counts prefixes where (prefix_length % 3) equals the number of unique characters in that prefix.
// Time complexity: O(n), where n is the length of the string.
// Space complexity: O(k), where k is the number of unique characters in the string (bounded by alphabet size).
class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size(),cnt=0,res=0;
        unordered_map<int,bool>mp;
        for (int i=0;i<n;i++)
            {
                if (mp.count(s[i])==0) {cnt++;mp[s[i]]=true;}

                if ((i+1)%3==cnt) res++;
            }
        return res;
    }
};
```