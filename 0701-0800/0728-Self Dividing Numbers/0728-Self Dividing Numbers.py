class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def isSelfDividing(num):
            x = num
            while num:
                num, d = divmod(num, 10)
                if d == 0 or x % d:
                    return False
            return True
        return [num for num in range(left, right + 1) if isSelfDividing(num)]
