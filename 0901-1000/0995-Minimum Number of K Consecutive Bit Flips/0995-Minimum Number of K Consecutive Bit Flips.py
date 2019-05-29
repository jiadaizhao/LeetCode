class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        flip = count = 0
        isFlipped = [0] * len(A)
        for i, a in enumerate(A):
            if i >= K:
                flip ^= isFlipped[i - K]
            if flip ^ a == 0:
                if i + K > len(A):
                    return -1
                flip ^= 1
                isFlipped[i] = 1
                count += 1
                
        return count
