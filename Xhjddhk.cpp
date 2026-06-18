```cpp
/**
 * Core idea: Implements a stack that supports O(1) retrieval of the minimum element.
 * This is achieved by using two internal stacks: one for the main elements and a
 * secondary stack to keep track of the minimum element encountered up to each point.
 * The minimum stack only stores a value if it is less than or equal to the current minimum,
 * ensuring its top always reflects the overall minimum for the current stack state.
 *
 * Time Complexity:
 * - Constructor: O(1)
 * - push: O(1)
 * - pop: O(1)
 * - top: O(1)
 * - getMin: O(1)
 * All operations run in constant time.
 *
 * Space Complexity:
 * - O(N), where N is the number of elements in the stack. In the worst case (e.g., elements
 *   pushed in descending order), the minimum tracking stack can store all N elements,
 *   similar to the main stack.
 */
class MinStack {
public:
        
    stack<int>st;
    stack<int>mn;
    int mni=INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if (mn.empty() || val <= mn.top()) {
            mn.push(val);
        }
    }
    
    void pop() {
        if (st.top() == mn.top()) {
            mn.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```