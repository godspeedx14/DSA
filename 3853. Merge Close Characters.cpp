```cpp
class Solution {
public:
    // Core idea: Constructs a string by appending characters from the input. A character is appended only if it's not among the 'k' most recently appended distinct characters. If adding a new distinct character exceeds 'k' tracked characters, the oldest tracked character is untracked.
    // Time complexity: O(N), where N is the length of the input string 's'.
    // Space complexity: O(N + k), where N is the length of 's' and 'k' is the window size.
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