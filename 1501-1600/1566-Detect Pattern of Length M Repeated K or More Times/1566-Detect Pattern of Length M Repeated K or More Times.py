class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        count = 0
        for i in range(len(arr) - m):
            if arr[i] != arr[i + m]:
                count = 0
            else:
                count += 1
                if count == (k - 1) * m:
                    return True
        return False
