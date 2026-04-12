class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>res;
        int x=0;
        for (auto i:matrix)
            {for(int j:i)
                x+=j;
            res.push_back(x); x=0;}

        return res;
    }
};