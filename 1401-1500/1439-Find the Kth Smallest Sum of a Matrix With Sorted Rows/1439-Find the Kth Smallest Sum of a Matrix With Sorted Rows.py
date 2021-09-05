import heapq
class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        def kSmallestPairs(nums1, nums2, k):
            pq = [(nums1[0] + nums2[0], 0, 0)]
            result = []
            while pq and k:
                s, col1 , col2 = heapq.heappop(pq)
                result.append(s)
                if col1 + 1 < len(nums1):
                    heapq.heappush(pq, (nums1[col1 + 1] + nums2[col2], col1 + 1, col2))
                if col1 == 0 and col2 + 1 < len(nums2):
                    heapq.heappush(pq, (nums1[col1] + nums2[col2 + 1], col1, col2 + 1))
                k -= 1
            return result
        
        nums1 = mat[0]
        for i in range(1, len(mat)):
            nums1 = kSmallestPairs(nums1, mat[i], k)
            
        return nums1[-1]
