```cpp
/*
 * Core Idea: Simulates adding one to a number represented as a vector of digits.
 * It iterates from the least significant digit, handling carry-overs. If a digit
 * is not 9, it's incremented and the process stops. If all digits are 9s, the
 * vector is expanded to accommodate the new most significant digit (e.g., [9,9] becomes [1,0,0]).
 *
 * Time Complexity: O(N), where N is the number of digits. In the worst case (all 9s),
 *                  it iterates through all digits and constructs a new vector of size N+1.
 * Space Complexity: O(1) in most cases (modifies input vector in-place). O(N) in the worst case
 *                   when a new vector of size N+1 is created (e.g., for [9,9]).
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--)
            {
                if (digits[i]==9)
                    {
                        digits[i]=0;
                    }
                else {
                    digits[i]+=1;
                    break;
                }
                if (i==0)
                    {
                        digits=vector<int> (1,1);
                        for(int j=0;j<n;j++)
                            {
                                digits.push_back(0);
                            }
                        break;
                    }
            }
        return digits;
    }
};
```