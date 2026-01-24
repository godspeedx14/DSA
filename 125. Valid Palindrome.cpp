```cpp
/*
 * Core Idea:
 * This function determines if a given string is a palindrome after converting all
 * uppercase letters to lowercase and removing all non-alphanumeric characters.
 * It builds a new string containing only the relevant characters, converts them
 * to lowercase, and then compares this processed string with its reverse.
 *
 * Time Complexity: O(N)
 * Where N is the length of the input string `s`.
 * - The initial loop iterates through `s` once, performing constant time operations
 *   and appending to `res`. Building `res` takes O(N) in total.
 * - Copying `res` to `rev` takes O(N) (length of `res` is at most N).
 * - Reversing `rev` takes O(N).
 * - Comparing `res` and `rev` takes O(N).
 *
 * Space Complexity: O(N)
 * Where N is the length of the input string `s`.
 * - The `res` string stores filtered characters, potentially up to N characters.
 * - The `rev` string stores a copy of `res`, also potentially up to N characters.
 */
class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(char & c:s)
            {
                bool flg=(c>='A' && c<='Z');
                
               if ((c>='a' && c<='z')|| c>='0' && c<='9' || flg) 
                    {
                        if (flg) c+='a'-'A';
                        
                        res.push_back(c);
                    }
            }
        string rev=res;
        reverse(rev.begin(),rev.end());
        return res==rev;
    }
};
```