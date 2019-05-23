class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        maxRight = [A[-1]] * len(A)
        for i in range(len(A) - 2, -1, -1):
            maxRight[i] = max(maxRight[i + 1], A[i])
        
        left = right = maxWid = 0
        while left < len(A) and right < len(A):
            if A[left] <= maxRight[right]:
                maxWid = max(maxWid, right - left)
                right += 1
            else:
                left += 1
        return maxWid


# Use stack to save different maxVal index only
class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        St = []
        for i in range(len(A) - 1, -1, -1):
            if not St or A[i] > A[St[-1]]:
                St.append(i)
                
        maxWid = 0
        for i in range(len(A)):
            while St and A[i] <= A[St[-1]]:
                maxWid = max(maxWid, St.pop() - i)
        return maxWid
