```cpp
/*
 * Core Idea: Removes all trailing vowels from the input string.
 *            It iterates from the end, stopping at the first non-vowel character,
 *            and returns the substring up to that point (inclusive).
 *            If the string contains only vowels, an empty string is returned.
 * Time Complexity: O(N), where N is the length of the input string 's'.
 *                  The algorithm iterates through the string at most once, and substr operation takes O(N) time.
 * Space Complexity: O(N), where N is the length of the input string 's'.
 *                   A new string is created to store the result.
 */
class Solution {
public:

    bool isvowel(char i)
    {return i=='a'||i=='e'||i=='i'||i=='o'||i=='u';}


    string trimTrailingVowels(string s) {
        string res;
        int i=s.size()-1;
        
        for (;i>=0;i--)
            if (!isvowel(s[i]))
                break;
            
        return s.substr(0,i+1);
    }
};
```