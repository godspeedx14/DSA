```cpp
// Core idea: Stores pairs of adjacent elements (arr[i], arr[i-1]) into 'res' when a condition (cur == dif) is met.
// Time complexity: O(1) per line execution. Assumes constant time array access and vector push_back operation.
// Space complexity: O(1) auxiliary per line for temporary object creation; O(K) for 'res' where K is the total count of matching pairs.
if (cur==dif) res.push(vector<int>{arr[i],arr[i-1]});
```