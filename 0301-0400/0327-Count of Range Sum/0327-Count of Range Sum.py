class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        presum = [0] * (1 + len(nums))
        for i in range(len(nums)):
            presum[i + 1] = presum[i] + nums[i]
        temp = [0] * (1 + len(nums))
        def mergeSort(start, end):
            count = 0
            if start < end:
                mid = (start + end) // 2
                count += mergeSort(start, mid)
                count += mergeSort(mid + 1, end)
                i, j = start, mid + 1
                p, q = mid + 1, mid + 1
                k = start
                while i <= mid:
                    while p <= end and presum[p] - presum[i] < lower:
                        p += 1
                    while q <= end and presum[q] - presum[i] <= upper:
                        q += 1
                    count += q - p
                    
                    while j <= end and presum[i] > presum[j]:
                        temp[k] = presum[j]
                        k += 1
                        j += 1
                    temp[k] = presum[i]
                    k += 1
                    i += 1
                
                while j <= end:
                    temp[k] = presum[j]
                    k += 1
                    j += 1
                presum[start:end+1] = temp[start:end+1]
            return count
        
        return  mergeSort(0, len(nums))
