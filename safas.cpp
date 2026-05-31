/*
 * Core Idea: Concatenates text chunks, then extracts and counts word occurrences based on specific rules (lowercase letters, internal hyphens only). Finally, it returns the frequency for each given query word.
 * Time Complexity: O(L_chunks + L_queries), where L_chunks is the total length of all input chunks, and L_queries is the total length of all query strings. This assumes average-case performance for unordered_map operations.
 * Space Complexity: O(L_chunks + Q), where L_chunks is the total length of all input chunks, and Q is the number of queries. This accounts for storing the concatenated text, unique words in the map, and the result vector.
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