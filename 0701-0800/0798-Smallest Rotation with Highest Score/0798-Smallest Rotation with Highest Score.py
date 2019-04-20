class Solution:
    def bestRotation(self, A: List[int]) -> int:
        change = [0] * len(A)
        for i in range(len(A)):
            change[(i - A[i] + 1) % len(A)] -= 1
        K = 0
        for i in range(1, len(A)):
            change[i] += change[i - 1] + 1
            if change[i] > change[K]:
                K = i
        return K
