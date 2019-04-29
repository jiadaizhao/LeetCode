class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        time = [(target - p) / s for p, s in sorted(zip(position, speed))]
        count = curr = 0
        for t in time[::-1]:
            if t > curr:
                count += 1
                curr = t
        return count
