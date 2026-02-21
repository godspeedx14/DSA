```cpp
/*
 * Core Idea:
 * This function simulates toggling light bulbs. It uses a boolean array to track the on/off state of 100 bulbs (1-indexed).
 * For each bulb number provided in the input, it flips the corresponding bulb's state.
 * Finally, it returns a list of all bulbs that are currently on.
 *
 * Time Complexity:
 * O(N), where N is the number of elements in the input 'bulbs' vector.
 * The initial state setup and the final collection loop run in constant time (100 operations).
 * The primary loop iterates N times.
 *
 * Space Complexity:
 * O(1).
 * A boolean array of fixed size 100 and a result vector (max 100 elements) are used, both contributing constant space.
 */
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> ar(100,false);
        vector<int>res;
        for(int i:bulbs)
            ar[i-1]=!ar[i-1];

        
        for(int i=0;i<100;i++)
            if (ar[i]) res.push_back(i+1);    

        return res;
    }
};
```