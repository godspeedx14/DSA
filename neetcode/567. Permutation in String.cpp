class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0),v2(26,0);
        
        for(char c:s1)
            v2[c-'a']++;

        int n=s2.size(),m=s1.size();
        if (m>n) return false;
        int l=0,r=0;
        while (r<m)
            v1[s2[r]-'a']++,r++;
        while(r<n)
            if (v1==v2) return true;
            else v1[s2[l]-'a']--,v1[s2[r]-'a']++,l++,r++;

        if (v1==v2)return true;
        return false;

    }
};
