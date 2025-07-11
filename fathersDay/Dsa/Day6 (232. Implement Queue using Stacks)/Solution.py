class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, x: int) -> None:
        self.stack1.append(x)
    def pop(self) -> int:
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop() if self.stack2 else -1
    def peek(self) -> int:
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2[-1] if self.stack2 else -1
    def empty(self) -> bool:
        return not self.stack1 and not self.stack2
# Example usage
solution = Solution()
solution.push(1)
solution.push(2)
print(solution.peek())
print(solution.pop())   
print(solution.empty()) 