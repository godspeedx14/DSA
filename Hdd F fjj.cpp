```cpp
/*
 * Core Idea: Calculates the internal angles of a triangle given its three side lengths.
 *            It first sorts the side lengths, validates the triangle inequality, then
 *            applies the Law of Cosines to find two angles, and derives the third.
 *            The resulting angles are returned in sorted order.
 *
 * Time Complexity: O(1) - All operations (sorting 3 elements, arithmetic, acos) are constant time.
 * Space Complexity: O(1) - Stores a fixed number of variables and a result vector of fixed size (3 doubles).
 */
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        sort(sides.begin(),sides.end());
        int a=sides[0],b=sides[1],c=sides[2];
        
        if (a+b<=c) return {};

        double A=acos((b*b + c*c - a*a)/(2.0*b*c))*180.0/M_PI;
        double B=acos((a*a + c*c - b*b)/(2.0*a*c))*180.0/M_PI;
        double C=180.0-A-B;
        
        vector<double>ans={A,B,C};
        sort(ans.begin(),ans.end());

        return ans;
    }
};
```