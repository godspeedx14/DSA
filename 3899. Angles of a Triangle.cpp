```cpp
/*
 * Core Idea: Calculates the internal angles of a triangle given three side lengths.
 *            It first validates the triangle using the triangle inequality theorem,
 *            then applies the Law of Cosines to determine two angles, and derives the third.
 *            The resulting angles are returned in sorted order.
 *
 * Time Complexity: O(1) - Operations involve sorting fixed-size arrays (3 elements) and constant-time math.
 * Space Complexity: O(1) - Uses a fixed amount of memory for variables and the result vector.
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