```cpp
/*
 * Core Idea: Evaluates a Reverse Polish Notation (RPN) expression by using a stack.
 *            Numbers are pushed onto the stack; upon encountering an operator, the top two operands are popped,
 *            the operation is performed, and the result is pushed back onto the stack.
 * Time Complexity: O(N), where N is the number of tokens. Each token is processed once with constant time stack operations.
 * Space Complexity: O(N), where N is the number of tokens. In the worst case, the stack may store up to N numbers.
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