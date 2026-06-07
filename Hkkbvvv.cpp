```cpp
/*
 * Core idea: Uses a sliding window approach with two frequency arrays (hash maps)
 *            to check if any window of size s1.length() in s2 has the same
 *            character frequencies as s1.
 * Time complexity: O(N + M), where N is the length of s2 and M is the length of s1.
 *                  This is because we iterate through s1 once to build its frequency map
 *                  and then iterate through s2 once using a sliding window.
 * Space complexity: O(1) as the frequency arrays are of fixed size 26 (for lowercase English letters).
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0),v2(26,0);
        
        for(char c:s1)
            v2[c-'a']++;

        int n=s2.size(),m=s1.size();
        if (m>n) return false;
        int l=0,r=0;
        while (r<m)
            v1[s2[r]-'a']++,r++;
        while(r<n)
            if (v1==v2) return true;
            else v1[s2[l]-'a']--,v1[s2[r]-'a']++,l++,r++;

        if (v1==v2)return true;
        return false;

    }
};
```