#include <stack>
#include <algorithm> // For std::min

class MinStack {
public:
    std::stack<int> mainStack; // Stores all elements
    std::stack<int> minStack;  // Stores minimum elements

    MinStack() {
        // Constructor, no special initialization needed for stacks
    }
    
    void push(int val) {
        mainStack.push(val);
        // Push to minStack only if it's empty or the new value is less than or equal to the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (mainStack.empty()) {
            return; // Or throw an exception, depending on problem constraints
        }
        // If the value being popped from mainStack is the current minimum, pop from minStack as well
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        if (mainStack.empty()) {
            // Handle error: stack is empty
            // For competitive programming, often assume valid calls
            // return some default or throw exception
            return -1; // Example: return -1 or throw std::runtime_error("Stack is empty");
        }
        return mainStack.top();
    }
    
    int getMin() {
        if (minStack.empty()) {
            // Handle error: minStack is empty (mainStack must also be empty)
            return -1; // Example: return -1 or throw std::runtime_error("Stack is empty");
        }
        return minStack.top();
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