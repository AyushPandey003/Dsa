from collections import deque
class MyStack:

    def __init__(self):
        self.queue = deque()

    def push(self, x):
        q = self.queue
        q.append(x)
        for _ in range(len(q) - 1):
            q.append(q.popleft())
        
    def pop(self):
        return self.queue.popleft()

    def top(self):
        return self.queue[0]
    
    def empty(self):
        return not len(self.queue)
    
# Your MyStack object will be instantiated and called as such:
obj= MyStack()
k=["MyStack","push","push","top","pop","empty"]
for i in range(len(k)):
    if k[i] == "MyStack":
        obj = MyStack()
        print("Stack initialized")
    elif k[i] == "push":
        obj.push(i+1)
        print(f"Pushed {i+1} onto stack")
    elif k[i] == "top":
        print(f"Top element is {obj.top()}")
    elif k[i] == "pop":
        print(f"Popped {obj.pop()} from stack")
