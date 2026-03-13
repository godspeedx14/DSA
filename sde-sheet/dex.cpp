```cpp
// Core idea: This function constructs a new string by iterating through the input string 's'.
// It appends a character 'c' from 's' to the result only if 'c' is not present in a dynamically
// maintained sliding window of 'k' unique characters. The window tracks the 'k' most recently
// encountered unique characters.
// Time complexity: O(N), where N is the length of the input string 's'. Each character is processed once
// with average O(1) operations for hash map and queue.
// Space complexity: O(N + k), where N is the length of the input string 's' (for the result string)
// and k is the window size (for the hash map and queue).
class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char,bool>mp;
        queue<int>q;
        string res;
        
        for(char c:s)
            {
                if (mp[c]) continue;

                res.push_back(c);
                
                mp[c]=true;
                q.push(c);
                
                if (q.size()>k)
                {
                 mp[q.front()]=false;
                 q.pop();
                }
                
            }
        
        return res;
    }
};
```