class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        table = {p[0]: p for p in pieces}
        result = []
        for a in arr:
            if a in table:
                result += table[a]
        return result == arr
