```cpp
/*
 * Core Idea:
 * This algorithm finds the longest substring where, by changing at most 'k'
 * characters, all characters in the substring become the same. It employs a
 * sliding window approach, expanding the window from 'l' to 'r'. The window's
 * validity is checked by ensuring that (window_length - max_frequency_of_any_char)
 * is less than or equal to 'k'. If valid, the window is expanded; otherwise,
 * it is shrunk from the left.
 *
 * Time Complexity: O(N)
 * The two pointers 'l' and 'r' traverse the string at most once. Operations
 * inside the loop, such as frequency updates and finding the maximum frequency
 * in a fixed-size alphabet (26), are constant time.
 *
 * Space Complexity: O(1)
 * A fixed-size array (26 elements for English alphabet characters) is used
 * to store character frequencies within the current window.
 */
class Solution {
public:
int mx(vector<int>v)
{
    int mix=0;
    for(int i:v)
        mix=max(i,mix);
    return mix;
}

int characterReplacement(string s, int k) {
      vector<int>v(26,0);
      int n=s.size();
        int l=0,r=0;
        int high=0;

        while(r<n)
        {  
            v[s[r]-'A']++;
            if ((r-l+1)-mx(v)<=k) high=max(high,r-l+1);
            else v[s[l]-'A']--,l++;
            r++;
        }


        return high;
    }
};
```