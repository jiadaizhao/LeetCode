class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        n = len(arr)
        table = [set() for _ in range(n)]
        # table[i] -> contains **unique** AND values of subarrays starting from ith index
        table[-1] = set([arr[-1]])
        for i in range(n - 2, -1, -1):
            table[i].add(arr[i])
            for val in table[i + 1]:
                table[i].add(arr[i] & val)
                
        return min(abs(val - target) for i in range(n) for val in table[i])
