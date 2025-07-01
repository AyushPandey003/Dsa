import java.util.Stack;

class MinStack {
    private Stack<Integer> mainStack; // Stores all elements
    private Stack<Integer> minStack;  // Stores minimum elements

    public MinStack() {
        mainStack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int val) {
        mainStack.push(val);
        // Push to minStack only if it's empty or the new value is less than or equal to the current minimum
        if (minStack.empty() || val <= minStack.peek()) {
            minStack.push(val);
        }
    }
    
    public void pop() {
        if (mainStack.empty()) {
            return; // Or throw an exception
        }
        // If the value being popped from mainStack is the current minimum, pop from minStack as well
        if (mainStack.peek().equals(minStack.peek())) { // Use .equals for Integer comparison
            minStack.pop();
        }
        mainStack.pop();
    }
    
    public int top() {
        if (mainStack.empty()) {
            // Handle error: stack is empty
            // For competitive programming, often assume valid calls
            // return some default or throw exception
            throw new IllegalStateException("Stack is empty");
        }
        return mainStack.peek();
    }
    
    public int getMin() {
        if (minStack.empty()) {
            // Handle error: minStack is empty (mainStack must also be empty)
            throw new IllegalStateException("Stack is empty");
        }
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */