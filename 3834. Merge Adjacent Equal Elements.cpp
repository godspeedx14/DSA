```cpp
class Solution {
public:
    /*
     * Core Idea: Processes numbers sequentially, maintaining a stack-like structure.
     *            When a new number is pushed, if it's equal to the current top,
     *            they merge by doubling the top element and removing the pushed one.
     *            This merging process repeats until the top two elements are distinct
     *            or only one element remains, similar to the game 2048.
     * Time Complexity: O(N), where N is the size of the input array `nums`. Each element
     *                  is pushed onto the result vector once, and an element in the result
     *                  vector is popped at most a logarithmic number of times (as its value doubles).
     *                  Overall, each element performs a constant number of amortized operations.
     * Space Complexity: O(N), where N is the size of the input array `nums`, as the result
     *                   vector can store up to N elements in the worst case.
     */
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;
        int n=nums.size(),j=0;

        for(int i=0;i<n;i++)
        {res.push_back(nums[i]);
             while(j>0 && res[j]==res[j-1])
            {
                j--;
                res.pop_back();
                res[j]+=res[j];
            }
            j++; 
        }
        return res;
    }
};
```