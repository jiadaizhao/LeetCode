class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        result = [0] * n
        if k == 0:
            return result
        if k > 0:
            start, end = 1, k
        else:
            k = -k
            start, end = n - k, n - 1
        curr = sum(code[start : end + 1])
        for i in range(n):
            result[i] = curr
            curr -= code[start]
            start = (start + 1) % n
            end = (end + 1) % n
            curr += code[end]
        return result
