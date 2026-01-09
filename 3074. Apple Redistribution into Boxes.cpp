```cpp
/*
 * Core Idea: To minimize the number of boxes used to store a total weight of apples,
 * a greedy strategy is employed: always choose the box with the largest available capacity.
 * The algorithm first calculates the total weight of all apples. Then, it iteratively
 * selects the largest capacity boxes (using a max-priority queue) until the total
 * capacity of selected boxes is greater than or equal to the total apple weight.
 * The count of boxes used is returned.
 *
 * Time Complexity: O(N + M log M)
 *   - O(N) to sum the weights of N apples.
 *   - O(M log M) to populate the priority queue with M box capacities (each insertion takes O(log M)).
 *   - O(K log M) in the worst case for the while loop, where K is the number of boxes used (K <= M),
 *     as each `top()` and `pop()` operation on the priority queue takes O(log M).
 *   The dominant term is M log M.
 *
 * Space Complexity: O(M)
 *   - O(M) to store all M box capacities in the priority queue.
 */
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long sum=0;
        for (int& i:apple)
            sum+=i;

        priority_queue<int>pq;

        for( int& i:capacity)
            pq.push(i);

int cnt=0;
        while(sum>0)
            {
            cnt++;
            sum-=pq.top();
            pq.pop();
            }
        return cnt;
    }
};
```