class MyQueue:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.St1 = []
        self.St2 = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.St1.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        result = self.peek()
        self.St2.pop()
        return result

    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.St2:
            while self.St1:
                self.St2.append(self.St1.pop())
                
        return self.St2[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.St1) == 0 and len(self.St2) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
