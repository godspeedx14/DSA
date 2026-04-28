```cpp
// Core idea: Sorts vowels in a string alphabetically, preserving consonant positions.
// It counts vowel occurrences and their first indices. A custom sort on (count, vowel) pairs,
// followed by a reverse mapping, constructs an alphabetically ordered list of all unique vowels
// and their counts. The string is then traversed, replacing original vowels with elements from
// this sorted list in their encountered order.
// Time complexity: O(N), where N is the length of the input string.
// Space complexity: O(1), for fixed-size auxiliary data structures (vectors and map).
class Solution {
public:
     bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    
    string sortVowels(string s) {
        //a=0,e=1,i=2,o=3,u=4
        int n=s.size();

        vector<int>v={0,0,0,0,0};

        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++)
            {
            if (isVowel(s[i]) && !mp.count(s[i])) mp[s[i]]=i;
                
            if (s[i]=='a') v[0]++;
            if (s[i]=='e') v[1]++;
            if (s[i]=='i') v[2]++;
            if (s[i]=='o') v[3]++;
            if (s[i]=='u') v[4]++;

            }

        vector<char>c={'a','e','i','o','u'};
        
        vector<pair<int,char>>y={{v[0],'a'},{v[1],'e'},{v[2],'i'},{v[3],'o'},{v[4],'u'}};

        sort(y.begin(), y.end(), [&](pair<int,char> a, pair<int,char> b) {
        if(a.first == b.first)
            return mp[a.second] > mp[b.second]; // tie-breaker
        return a.first < b.first; // main condition
        });
        
        int i=4;
        for (auto z:y)
            v[i]=z.first,c[i]=z.second,i--;
            
        int j=0;
        
        for(int i=0;i<n;i++)
            {
                while(j < 5 && !v[j]) j++;
                if (isVowel(s[i]))
                    s[i]=c[j],v[j]--;
                
            }

        return s;

        
                
    }
};
```