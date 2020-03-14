class Solution:
    def isHappy(self, n: int) -> bool:
        visited = {n}
        while n != 1:
            curr = n
            n = 0
            while curr:
                n += (curr % 10) ** 2
                curr //= 10
            if n in visited:
                return False
            visited.add(n)

        return True
