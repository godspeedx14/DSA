```cpp
/*
 * Core Idea: Counts occurrences of words (lowercase letters and internal hyphens) within concatenated text chunks. Returns counts for specified queries.
 * Time Complexity: O(L + Q * M), where L is the total length of all text chunks, Q is the number of queries, and M is the maximum length of a query string (average case for unordered_map operations).
 * Space Complexity: O(L + Q), where L is the total length of all text chunks (for concatenated text and map keys) and Q is the number of queries (for the result vector).
 */
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int>mp;

        string x="";
        for(auto &j:chunks)
            x+=j;
        
        string cur="";

        int n=x.size();
        for(int i =0;i<n;i++)
            if ('a'<=x[i] && x[i]<='z')
                cur+=x[i];
            else if (x[i]=='-' && !cur.empty() && i+1<n && 'a'<=x[i+1] && x[i+1]<='z')
                cur+=x[i];
            else
                {if (!cur.empty() && cur[cur.size()-1]!='-')
                    mp[cur]++;
                cur="";}

        if (!cur.empty() && cur[cur.size()-1]!='-')
            mp[cur]++;
        vector<int>ans;
        for(auto &wor :queries)
            ans.push_back(mp[wor]);
        
        return ans;
    }
};
```