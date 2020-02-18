class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        result = []
        i = j = 0
        while i < len(A) and j < len(B):
            if A[i][1] < B[j][0]:
                i += 1
            elif B[j][1] < A[i][0]:
                j += 1
            else:
                start = max(A[i][0], B[j][0])
                end = min(A[i][1], B[j][1])
                result.append([start, end])
                
                if A[i][1] <= B[j][1]:
                    i += 1
                else:
                    j += 1
        return result


class Solution2:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        result = []
        i = j = 0
        while i < len(A) and j < len(B):
            start = max(A[i][0], B[j][0])
            end = min(A[i][1], B[j][1])
            if start <= end:
                result.append([start, end])
            
            if A[i][1] <= B[j][1]:
                i += 1
            else:
                j += 1
        
        return result
                