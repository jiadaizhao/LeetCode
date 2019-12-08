class Solution:
    def longestRepeatingSubstring(self, S: str) -> int:      
        def search(L):
            visited = set()
            for i in range(len(S) - L + 1):
                s = S[i: i + L]
                if s in visited:
                    return i
                visited.add(s)
            return -1
        
        low, high = 1, len(S)
        while low < high:
            mid = (low + high) // 2
            if search(mid) != -1:
                low = mid + 1
            else:
                high = mid
        return low - 1
