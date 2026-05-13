```cpp
/*
 * Core Idea: Evaluates a Reverse Polish Notation (RPN) expression using a stack. 
 *            Numbers are pushed onto the stack. When an operator is encountered, 
 *            the top two operands are popped, the operation is performed, and the result is pushed back.
 * Time Complexity: O(N), where N is the number of tokens. Each token is processed once.
 * Space Complexity: O(N), where N is the number of tokens. In the worst case, all tokens are numbers stored on the stack.
 */
class Solution {
public:

 
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
        for(string i:tokens)
            if (i=="+"||i=="-"||i=="*"||i=="/")
            {int y=st.top();st.pop();
             int x=st.top();st.pop();
             int z;
             if (i=="+")
                 z=x+y;
             else if (i=="-") z=x-y;
        else if (i=="*") z=x*y;
      else if (i=="/") z=x/y;
             st.push(z);}
    else
        {
            st.push(stoi(i));
        }
    
    return st.top();}
};
```