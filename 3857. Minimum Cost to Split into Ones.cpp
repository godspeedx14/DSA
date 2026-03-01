```cpp
/*
 * Core Idea:
 * This function calculates the total cost to cut a stick of length 'n' into unit pieces.
 * The cutting strategy is recursive: if the current stick length 'i' is even, it's split
 * into two equal halves (i/2, i/2); if 'i' is odd, it's split into (i/2, i/2+1).
 * The cost of a single cut is defined as the product of the lengths of the two resulting pieces.
 * This process continues until all pieces are of length 1.
 *
 * Time Complexity:
 * O(n), where 'n' is the input value. Each recursive call reduces the problem size by approximately half.
 * Despite potential re-computation of subproblems due to lack of memoization, the total number of
 * recursive calls for this specific recurrence pattern remains proportional to 'n'.
 *
 * Space Complexity:
 * O(log n), due to the maximum depth of the recursion stack.
 */
class Solution {
public:
    bool isodd(int i)
    {return i%2;}

    int cst(int i)
    {
        if (i==1||i==2) return i-1;
        if (i==3) return 3;
        
        if (isodd(i))
            return cst(i/2)+cst(i/2+1)+(i/2)*(i/2+1);
        else
            return cst(i/2)*2+(i/2)*(i/2);
    }
    
    int minCost(int n) {
        return cst(n);
    }
};
```