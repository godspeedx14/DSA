```cpp
// Core Idea: Finds the first pair of distinct numbers (x, y) from the sorted input array 
//            such that their frequencies are different. Returns {x, y} if found, else {-1, -1}.
// Time Complexity: O(N log N) due to sorting, where N is the number of elements in 'nums'.
// Space Complexity: O(log N) for the recursion stack used by std::sort, or O(1) if considering only auxiliary space for variables.
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int x=nums[0],xcnt=0;

        while(i<n && nums[i]==x)
            i++,xcnt++;

        int flg=0;
        
        for(;i<n;i++)
            {
                int y=nums[i];
                int ycnt=1;
                while (i+1<n && nums[i]==nums[i+1])
                    ycnt++,i++;

                if (ycnt!=xcnt)
                    return vector<int> {x,y};
            }
        return vector<int>{-1,-1};
        }
};
```