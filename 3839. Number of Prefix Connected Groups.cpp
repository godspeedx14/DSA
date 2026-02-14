```cpp
/**
 * Core idea: Counts the number of unique prefixes of length `k` that appear at least twice across all input `words`.
 *            An unordered_map tracks prefixes and marks them 'true' once they've been observed for a second time.
 * Time complexity: O(N * k), where N is the number of words and k is the prefix length.
 *                  Each word iteration involves substring extraction and hash map operations, both O(k) on average.
 * Space complexity: O(M * k), where M is the number of distinct prefixes of length `k` encountered (M <= N).
 *                   The hash map stores these distinct prefixes, each of length `k`.
 */
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,bool>mp;
        int res=0;
        for(auto w:words)
            {
                if (w.size()>=k)
                    {
                    string x=w.substr(0,k);
                    if (mp.contains(x))
                    {
                        if(!(mp[x]))
                            {res++;
                            mp[x]=true;}
                    }
                    else
                    mp[x]=false;
                    }
            }

        return res;
    }
};
```