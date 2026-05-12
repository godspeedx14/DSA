```cpp
/**
 * Core idea: This function concatenates all input text chunks into a single string. It then parses this string
 * to identify individual words, considering lowercase letters and specific hyphenation rules.
 * The parsed words and their frequencies are stored in a hash map. Finally, it retrieves and returns
 * the frequencies for each word specified in the queries.
 *
 * Time complexity: O(N + Q * L_q)
 *   - N: Total length of all characters across all input `chunks`. This accounts for concatenating chunks,
 *        and iterating through the combined string to parse words and populate the hash map.
 *        Map insertion/access for string keys takes time proportional to the key's length;
 *        the sum of all word lengths in the map is at most N.
 *   - Q: Number of `queries`.
 *   - L_q: Average length of a query word. Each query lookup in the map takes O(L_q) on average.
 *
 * Space complexity: O(N + Q)
 *   - N: For storing the concatenated string (`x`) and the unique words (keys) in the hash map (`mp`).
 *        The total length of unique words stored in the map is at most N.
 *   - Q: For storing the result vector (`ans`).
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