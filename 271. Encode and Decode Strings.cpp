```cpp
/*
* Core Idea:
*   The `encode` function serializes a sentence by transforming each word into a length-prefixed format: "[length]#[word]".
*   The `decode` function reconstructs the original sentence from this serialized format by parsing the length and then extracting the word.
*   This approach is useful for reliably transmitting or storing a list of strings without ambiguous delimiters.
*
* Time Complexity:
*   encode(string x): O(N), where N is the length of the input string x. Each character is processed once.
*   decode(string y): O(M), where M is the length of the encoded string y. Each character is processed once.
*   (Note: M is roughly proportional to N, so decode is also O(N) in terms of original string length).
*
* Space Complexity:
*   encode(string x): O(N), as the encoded string's length is proportional to the input string's length.
*   decode(string y): O(N), as the decoded string's length is proportional to the original string's length.
*/
#include <bits/stdc++.h>
using namespace std;

string encode(string x)
{
    //hello how are you
    string res,cur;
    int cnt=0;
    for(char &i:x)
    {
        if (i!=' ')
            cur+=i,cnt++;
        else
            {
                res+=to_string(cnt);
                res+='#';
                res+=cur;
                
                cur="";
                cnt=0;
            }
    }
    res+=to_string(cnt);
    res+='#';
    res+=cur;
    return res;
}

string decode(string y)
{
 string res="",cur="";
 int sz=y.size();
 
 for(int i=0;i<sz;i++)
    {
        if(y[i]!='#')
            cur+=y[i];
        else
            {
                int cnt=stoi(cur);
                cur="";
                int j;
                
                for(j=i+1;j<i+cnt+1;j++)
                    res+=y[j];
                
                res+=' ';
                i=j-1;
            }
    }
    res.pop_back();
    return res;
 
}

int main() {
    string x;
    x="hello how  are you";
    string y=encode(x);
    cout<<y<<endl;
    y=decode(y);
    cout<<y;
    return 0;
}
```