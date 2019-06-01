class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        low = max(weights)
        high = sum(weights)
        while low < high:
            mid = (low + high) // 2
            count = 1
            s = 0
            for w in weights:
                s += w
                if s > mid:
                    count += 1
                    s = w
            
            if count <= D:
                high = mid
            else:
                low = mid + 1
        return low
