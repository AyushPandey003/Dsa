import java.util.Stack;

class MyQueue {
    private Stack<Integer> stack1; // For pushing elements
    private Stack<Integer> stack2; // For popping/peeking elements

    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void push(int x) {
        stack1.push(x);
    }
    
    public int pop() {
        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.pop());
            }
        }
        // Pop from stack2
        return stack2.pop();
    }
    
    public int peek() {
        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.pop());
            }
        }
        // Peek from stack2
        return stack2.peek();
    }
    
    public boolean empty() {
        return stack1.empty() && stack2.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */