class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        result = [0] * length
        for start, end, inc in updates:
            result[start] += inc
            if end + 1 < length:
                result[end + 1] -= inc
        for i in range(1, length):
            result[i] += result[i - 1]
        return result
