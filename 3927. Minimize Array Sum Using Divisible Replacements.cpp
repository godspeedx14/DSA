```cpp
/*
 * Core idea: Iterates through the sorted input array. For each number, if it is divisible by any previously "selected" unique number, the smallest such divisor from the selected numbers is added to the total sum. Otherwise, the number itself is added to the sum and becomes a new "selected" number for future checks.
 * Time complexity: O(N^2), where N is the number of elements in `nums`. This is due to the O(N log N) sorting followed by nested loops which can be O(N^2) in the worst case.
 * Space complexity: O(N) for storing the `test` vector.
 */
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans=0;

        sort(nums.begin(),nums.end());

        int n=0;
        vector<int>test;
        
        for(auto i:nums)
            {
            bool flg=0;
            for(int j=0;j<n;j++)
                if (i%test[j]==0)
                {
                    ans+=test[j];
                    flg=1;
                    break;
                }
            if (flg) continue;
            ans+=i;
            test.push_back(i);
            n++;
            }

        return ans;
    }
};
```