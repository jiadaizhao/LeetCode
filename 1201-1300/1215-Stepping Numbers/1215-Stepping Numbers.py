import collections
class Solution:
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        result = [0] if low == 0 else []
        Q = collections.deque([i for i in range(1, 10)])
        while Q:
            curr = Q.popleft()
            if low <= curr <= high:
                result.append(curr)
            if curr <= high // 10:
                d = curr % 10
                if d > 0:
                    Q.append(curr * 10 + d - 1)
                if d < 9:
                    Q.append(curr * 10 + d + 1)
        return result
