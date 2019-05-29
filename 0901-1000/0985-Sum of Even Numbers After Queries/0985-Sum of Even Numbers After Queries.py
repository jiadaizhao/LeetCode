class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        s = sum(a for a in A if (a & 1) == 0)
        result = [0] * len(queries)
        for i, (val, index) in enumerate(queries):
            if A[index] & 1:
                if val & 1:
                    s += A[index] + val
            else:
                if val & 1:
                    s -= A[index]
                else:
                    s += val
                    
            A[index] += val
            result[i] = s
        return result
