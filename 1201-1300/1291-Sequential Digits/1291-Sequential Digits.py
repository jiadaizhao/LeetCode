class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result = []
        for i in range(1, 9):
            num = d = i
            while num <= high:
                if num >= low:
                    result.append(num)
                d += 1
                if d >= 10:
                    break
                num = num * 10 + d

        return sorted(result)


class Solution2:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        def search():
            for i in range(1, 9):
                num = d = i
                while num <= high:
                    if num >= low:
                        yield num
                    d += 1
                    if d >= 10:
                        break
                    num = num * 10 + d

        return sorted(search())
