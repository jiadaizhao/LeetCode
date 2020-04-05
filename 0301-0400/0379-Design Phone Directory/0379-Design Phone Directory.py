class PhoneDirectory:
    
    def __init__(self, maxNumbers: int):
        """
        Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory.
        """
        self.used = [False] * maxNumbers
        self.table = [i for i in range(maxNumbers)]
        self.index = 0
        

    def get(self) -> int:
        """
        Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available.
        """
        if self.index == len(self.used):
            return -1
        result = self.table[self.index]
        self.index += 1
        self.used[result] = True
        return result
        

    def check(self, number: int) -> bool:
        """
        Check if a number is available or not.
        """
        return 0 <= number < len(self.used) and not self.used[number]
        

    def release(self, number: int) -> None:
        """
        Recycle or release a number.
        """
        if self.check(number):
            return
        self.used[number] = False
        self.index -= 1
        self.table[self.index] = number        


# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
