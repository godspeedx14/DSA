/*
 * Core Idea: To maximize total happiness, sort the initial happiness values in ascending order. Then, iterate from the largest values, picking the top 'k' items. Each picked item's happiness is reduced by the count of previously picked items (deduction starts from 0 for the first pick).
 * Time Complexity: O(N log N) due to sorting the happiness array, where N is the number of items. The subsequent loop runs k times (O(k)).
 * Space Complexity: O(log N) typically, for the auxiliary space used by the `std::sort` algorithm (e.g., recursion stack for quicksort).
 */
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        long long res=0;
        int cur=0;
        sort (happiness.begin(),happiness.end());

        for (int i=n-1;i>=n-k;i--)
        {   int x=happiness[i];
            res+=(x>cur)?(x-cur):0;
            cur++;
        }

        return res;
    }
};