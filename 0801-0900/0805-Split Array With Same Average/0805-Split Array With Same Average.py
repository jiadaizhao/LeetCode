class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        total = sum(A)
        n = len(A)
        if all(total*i%n for i in range(n//2 + 1)):
            return False
        sums = [set() for _ in range(1 + n // 2)]
        sums[0].add(0)
        for num in A:
            for i in range(n//2, 0, -1):
                for s in sums[i - 1]:
                    sums[i].add(s + num)
        
        return any(total*i%n == 0 and total*i//n in sums[i] for i in range(1, 1 + n//2))
