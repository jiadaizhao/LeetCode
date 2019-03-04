import random
class Solution:

    def __init__(self, n_rows, n_cols):
        """
        :type n_rows: int
        :type n_cols: int
        """
        self.n_rows = n_rows
        self.n_cols = n_cols
        self.rem = n_rows * n_cols
        self.d = {}
        

    def flip(self):
        """
        :rtype: List[int]
        """
        index = random.randint(0, self.rem - 1)
        self.rem -= 1
        x = self.d.get(index, index)
        self.d[index] = self.d.get(self.rem, self.rem)
        return [x // self.n_cols, x % self.n_cols]
        

    def reset(self):
        """
        :rtype: void
        """
        self.d = {}
        self.rem = self.n_rows * self.n_cols
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()