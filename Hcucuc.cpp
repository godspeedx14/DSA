```cpp
class Solution {
public:
    // Core idea: Evaluate a Reverse Polish Notation (RPN) expression using a stack.
    // Operands are pushed onto the stack. When an operator is encountered, the top two operands are popped,
    // the operation is performed, and the result is pushed back onto the stack.
    // Time complexity: O(N), where N is the number of tokens, as each token is processed once with constant time stack operations.
    // Space complexity: O(N), where N is the number of tokens, due to the stack storing operands.
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