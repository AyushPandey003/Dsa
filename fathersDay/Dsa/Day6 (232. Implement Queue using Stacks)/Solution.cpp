#include <stack>

class MyQueue {
public:
    std::stack<int> stack1; // For pushing elements
    std::stack<int> stack2; // For popping/peeking elements

    MyQueue() {
        // Constructor, no special initialization needed for stacks
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // Pop from stack2
        int val = stack2.top();
        stack2.pop();
        return val;
    }
    
    int peek() {
        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // Peek from stack2
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */