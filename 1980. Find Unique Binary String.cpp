```cpp
// Core idea: This algorithm finds a binary string of length 'n' that is not present in the input list 'nums'.
// It does so by iteratively generating candidate binary strings: it starts with an all-zeros string,
// and if a candidate is found in 'nums', it modifies the candidate by flipping its 'i'-th bit to '1' (for an increasing 'i').
// The first candidate string not found in 'nums' is returned. Since there are 2^n possible strings and only 'n' are given,
// such a string is guaranteed to exist and be found by this specific generation pattern.
// Time Complexity: O(n^3)
//   - The outer while loop runs at most n+1 times (at most n modifications to 'res' plus one final check).
//   - Inside the loop, a linear scan through 'nums' takes O(n) string comparisons.
//   - Each string comparison takes O(n) time for strings of length 'n'.
//   - Total: O((n+1) * n * n) = O(n^3).
// Space Complexity: O(n)
//   - O(n) for storing the 'res' string.
//   - O(1) for other variables.
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();

        string res(n,'0');
        int i=0;
        while (true)
        {   
            bool flg=true;
            for (string x:nums)
                if (x==res)flg=false;
            
            if (flg) return res;

            res[i]='1';
            i++;
        }

        return res;
        
    }
};
```