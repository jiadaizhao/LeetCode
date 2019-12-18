class Solution:
    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        low, high = 1, sum(sweetness) // (K + 1)
        while low < high:
            mid = (low + high + 1) // 2
            count = curr = 0
            for s in sweetness:
                curr += s
                if curr >= mid:
                    count += 1
                    if count >= K + 1:
                        break
                    curr = 0
                    
            if count >= K + 1:
                low = mid
            else:
                high = mid - 1

        return low
