class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int>mp;

        string x="";
        for(auto &j:chunks)
            x+=j;
        
        string cur="";

        int n=x.size();
        for(int i =0;i<n;i++)
            if ('a'<=x[i] && x[i]<='z')
                cur+=x[i];
            else if (x[i]=='-' && !cur.empty() && i+1<n && 'a'<=x[i+1] && x[i+1]<='z')
                cur+=x[i];
            else
                {if (!cur.empty() && cur[cur.size()-1]!='-')
                    mp[cur]++;
                cur="";}

        if (!cur.empty() && cur[cur.size()-1]!='-')
            mp[cur]++;
        vector<int>ans;
        for(auto &wor :queries)
            ans.push_back(mp[wor]);
        
        return ans;
    }
};