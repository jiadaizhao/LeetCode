import collections
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Q = collections.deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.Q.append(x)
        for _ in range(len(self.Q) - 1):
            self.Q.append(self.Q.popleft())
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.Q.popleft()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.Q[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.Q


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
