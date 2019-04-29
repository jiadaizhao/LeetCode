class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        visited = set()
        duplicate = False
        diff = first = second = 0
        for i in range(len(A)):
            if A[i] != B[i]:
                diff += 1
                if diff == 1:
                    first = i
                elif diff == 2:
                    second = i
                else:
                    return False
            else:
                if A[i] in visited:
                    duplicate = True
                else:
                    visited.add(A[i])
        return (diff == 0 and duplicate == True) or (diff == 2 and A[first] == B[second] and A[second] == B[first])
