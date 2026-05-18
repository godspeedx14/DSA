```cpp
/*
 * Core idea: Uses a sliding window to find the longest substring without repeating characters.
 *            A hash map tracks the last seen index of each character. When a character repeats
 *            within the current window (defined by 'lst' and 'i'), the window's left boundary
 *            ('lst') is shifted past the previous occurrence of the repeating character.
 * Time complexity: O(N), where N is the length of the input string.
 * Space complexity: O(A), where A is the size of the character set (e.g., 256 for ASCII).
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;

        int mx=0,cnt=0;
        int n=s.size();
        int lst=0;

        for (int i=0;i<n;i++)
        { 
            if (mp.count(s[i]) && mp[s[i]]>=lst) mx=max(mx,cnt),cnt=i-mp[s[i]]-1,lst=mp[s[i]]; 

            mp[s[i]]=i;
            cnt++;
        }

        return max(mx,cnt);
    }
};
```