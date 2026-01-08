```cpp
/*
 * Core Idea: Reverses the prefix of the input string 's' from index 0 up to index k-1 (inclusive) in-place.
 * Time Complexity: O(k), as it iterates through approximately half of the 'k' characters in the prefix.
 * Space Complexity: O(1), as it uses a constant amount of extra space for variables.
 */
class Solution {
public:
    string reversePrefix(string s, int k) {
        int i =0,j=k-1;
        char x;
        while(i<j)
            {
                x=s[i];
                s[i]=s[j];
                s[j]=x;
                i++,j--;
            }
        return s;
    }
};
```