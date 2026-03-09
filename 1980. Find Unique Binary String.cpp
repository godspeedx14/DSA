```cpp
// Core idea: The algorithm generates a specific sequence of n+1 binary strings (0...0, then 10...0, 110...0, ..., 1...1).
// It iterates through this sequence, checking each string against the input list. Since there are n input strings,
// at least one string from the generated sequence must be unique, and that string is returned.
// Time complexity: O(n^3), where n is the number of strings and their length. The loop runs at most n+1 times,
// with each iteration comparing the candidate string against n input strings, taking O(n) per comparison.
// Space complexity: O(n) for the candidate binary string.
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