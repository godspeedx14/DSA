```cpp
// Core Idea: Calculates the total cost of all characters and identifies the character type with the highest accumulated cost. The minimum cost is then derived by subtracting this highest character-type cost from the total sum, effectively keeping only the most expensive character type.
// Time Complexity: O(N), where N is the length of the string `s`. The code iterates through the string once.
// Space Complexity: O(1), as the `unordered_map` stores at most 256 entries (for all possible character values), which is constant space.
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        int n=s.size();
        long long total=0,highest=0;
        
        for(int i=0;i<n;i++)
            mp[s[i]]+=cost[i],total+=cost[i],highest=max(highest,mp[s[i]]);

        return total-highest;
        
            
    }
};
```