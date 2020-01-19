import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = []
        for num in nums:
            heapq.heappush(pq, num)
            if len(pq) > k:
                heapq.heappop(pq)
        return pq[0]

import random
class Solution2:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(start, end):
            pivot = random.randint(start, end)
            nums[pivot], nums[end] = nums[end], nums[pivot]
            j = start
            for i in range(start, end):
                if nums[i] <= nums[end]:
                    nums[j], nums[i] = nums[i], nums[j]
                    j += 1
            nums[end], nums[j] = nums[j], nums[end]
            return j
        start = 0
        end = len(nums) - 1
        while True:
            index = partition(start, end)
            if index < len(nums) - k:
                start = index + 1
            elif index > len(nums) - k:
                end = index - 1
            else:
                return nums[index]
