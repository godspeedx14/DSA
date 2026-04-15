class Solution {
public:
int mx(vector<int>v)
{
    int mix=0;
    for(int i:v)
        mix=max(i,mix);
    return mix;
}

int characterReplacement(string s, int k) {
      vector<int>v(26,0);
      int n=s.size();
        int l=0,r=0;
        int high=0;

        while(r<n)
        {  
            v[s[r]-'A']++;
            if ((r-l+1)-mx(v)<=k) high=max(high,r-l+1);
            else v[s[l]-'A']--,l++;
            r++;
        }


        return high;
    }
};

