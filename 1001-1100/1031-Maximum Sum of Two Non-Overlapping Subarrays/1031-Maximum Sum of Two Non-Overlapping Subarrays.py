class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        presum = [0] * (len(A) + 1)
        for i in range(len(A)):
            presum[i + 1] = presum[i] + A[i]

        '''
        sumL: max sum of subarray with length L
        sumM: max sum of subarray with length M
        maxSum: max sum of 2 continuous subarrays
        '''
        sumL = presum[L]
        sumM = presum[M]
        maxSum = presum[L + M]
        for i in range(L + M, len(A)):
            sumL = max(sumL, presum[i - M + 1] - presum[i - M - L + 1])
            sumM = max(sumM, presum[i - L + 1] - presum[i - L - M + 1])
            # Either ending with subaray with length L or M
            maxSum = max(maxSum, sumM + presum[i + 1] - presum[i - L + 1], sumL + presum[i + 1] - presum[i - M + 1])        
            
        return maxSum
