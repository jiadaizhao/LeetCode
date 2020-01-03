import collections
class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        """
        self.width = width
        self.height = height
        self.food = food
        self.foodIndex = 0
        self.dq = collections.deque([[0, 0]])
        self.snake = set([0])
        

    def move(self, direction: str) -> int:
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        """
        head = self.dq[0][:]
        if direction == 'U':
            head[0] -= 1
        elif direction == 'L':
            head[1] -= 1
        elif direction == 'R':
            head[1] += 1
        else:
            head[0] += 1
        
        if not (0 <= head[0] < self.height and 0 <= head[1] < self.width):
            return -1
        tail = self.dq[-1]
        if head[0] * self.width + head[1] in self.snake and (head[0] != tail[0] or head[1] != tail[1]):
            return -1
        if (self.foodIndex < len(self.food) and
            head[0] == self.food[self.foodIndex][0] and
            head[1] == self.food[self.foodIndex][1]):
            self.foodIndex += 1
        else:
            self.dq.pop()
            self.snake.remove(tail[0] * self.width + tail[1])
            
        self.dq.appendleft(head)
        self.snake.add(head[0] * self.width + head[1])
        return len(self.dq) - 1


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
