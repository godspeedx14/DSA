```cpp
/*
 * Core idea: This algorithm counts pairs of "similar" words. Two words are similar if the character differences between adjacent characters are identical throughout their length. It transforms each word into a unique "difference string" (encoding character differences) and stores their frequencies in a hash map. The total number of similar pairs is then calculated by summing nC2 combinations (n * (n-1) / 2) for each frequency 'n' found.
 * Time complexity: O(N * M) on average, where N is the number of words and M is the length of each word. This is due to iterating N times, and for each word, processing M characters to build a difference string and perform hash map operations which take O(M) time for string keys.
 * Space complexity: O(N * M) in the worst case. The hash map stores up to N unique difference strings, each of length M.
 */
class Solution {
public:
    long long countPairs(vector<string>& words) {
       unordered_map<string,int>mp;
        int m=words[0].size();
       
       for (string& s:words)
           {string x;
           for (int i =0;i<m-1;i++)
               {
                   int dif=s[i+1]-s[i];
                   x.push_back((dif>0)? (char)dif : (char)dif+26);
               }
            mp[x]++;
           }

        long long res=0;
        for(auto a:mp)
            res+=1ll*a.second*(a.second-1)/2;
        return res;
    }
};
```