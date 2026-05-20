```cpp
/*
 * Core Idea:
 * This algorithm determines if s2 contains a permutation of s1 as a substring.
 * It uses a sliding window approach with two frequency maps (arrays) of size 26
 * to keep track of character counts. One map stores the frequencies of characters in s1,
 * and the other stores frequencies for the current sliding window in s2.
 * The window slides over s2, and at each step, its character frequencies are compared
 * with those of s1. If a match is found, a permutation exists.
 *
 * Time Complexity: O(N + M), where N is the length of s2 and M is the length of s1.
 *                  This accounts for initializing the s1 frequency map and then
 *                  iterating through s2 with the sliding window.
 * Space Complexity: O(1), as two fixed-size frequency arrays (26 characters each) are used.
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