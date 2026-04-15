```cpp
/**
 * Core idea: Uses a sliding window with a hash map to track the last seen index of each character. The window expands to the right, and its left boundary effectively shifts forward when a repeating character is found within the current non-repeating substring. The maximum length is updated throughout.
 * Time complexity: O(N), where N is the length of the string. Each character is processed once.
 * Space complexity: O(min(N, M)), where N is the length of the string and M is the size of the character set (e.g., 256 for ASCII).
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