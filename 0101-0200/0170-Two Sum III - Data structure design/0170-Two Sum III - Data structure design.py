class TwoSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.table = {}
        

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        self.table[number] = self.table.get(number, 0) + 1
        

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        for num1 in self.table:
            num2 = value - num1
            if num1 != num2:
                if num2 in self.table:
                    return True
            elif self.table[num1] > 1:
                return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
