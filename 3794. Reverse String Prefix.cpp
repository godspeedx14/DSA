```cpp
/**
 * Core Idea: Reverses the prefix of the input string `s` up to (and including) the character at index `k-1`.
 * Time Complexity: O(k) - The loop iterates approximately k/2 times to swap characters in the prefix.
 * Space Complexity: O(1) - Uses a constant amount of extra space for variables.
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