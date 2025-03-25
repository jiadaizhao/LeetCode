class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        result = [0] * (len(encoded) + 1)
        result[0] = first
        for i in range(1, len(encoded) + 1):
            result[i] = result[i - 1] ^ encoded[i - 1]
        return result
