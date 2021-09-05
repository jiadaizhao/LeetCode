import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        pq = [(nums1[0] + nums2[0], 0, 0)]
        result = []
        while pq and k:
            _, col1, col2 = heapq.heappop(pq)
            result.append([nums1[col1], nums2[col2]])
            if col1 + 1 < len(nums1):
                heapq.heappush(pq, (nums1[col1 + 1] + nums2[col2], col1 + 1, col2))
            
            if col1 == 0 and col2 + 1 < len(nums2):
                heapq.heappush(pq, (nums1[col1] + nums2[col2 + 1], col1, col2 + 1))
            
            k -= 1
        return result
