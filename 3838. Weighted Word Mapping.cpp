```cpp
// Core idea: For each word, calculate a total weight from character weights, take modulo 26, and map this value to a character ('z' to 'a'). Concatenate these characters into a result string.
// Time complexity: O(S), where S is the total number of characters across all input words.
// Space complexity: O(N), where N is the number of words (for the result string).
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for (auto w:words)
            {
                int wt=0;
                    for(char c:w)
                        wt+=weights[c-'a'];

                wt%=26;
                
                res.push_back('z'-wt);
            }
        return res;
    }
};
```