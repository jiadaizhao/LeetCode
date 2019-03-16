class Solution:
    def isHappy(self, n: int) -> bool:
        visited = {n}
        while n != 1:
            curr = n
            next = 0
            while curr:
                next += (curr % 10) ** 2
                curr //= 10
            if next in visited:
                return False
            visited.add(next)
            n = next
        return True
