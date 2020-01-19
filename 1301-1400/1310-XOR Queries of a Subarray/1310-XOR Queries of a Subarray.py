class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        preXor = [0] * (1 + len(arr))
        for i in range(1, len(preXor)):
            preXor[i] = preXor[i - 1] ^ arr[i - 1]
            
        return [preXor[R + 1] ^ preXor[L] for L, R in queries]
