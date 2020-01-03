class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        result = [0] * len(nums)
        index = [i for i in range(len(nums))]
        temp = [0] * len(nums)
        def mergeSort(start, end):
            if start < end:
                mid = (start + end) // 2
                mergeSort(start, mid)
                mergeSort(mid + 1, end)
                i = k = start
                j = mid + 1
                while i <= mid:
                    while j <= end and nums[index[j]] < nums[index[i]]:
                        temp[k] = index[j]
                        k += 1
                        j += 1
                    result[index[i]] += j - mid - 1
                    temp[k] = index[i]
                    k += 1
                    i += 1
                    
                while j <= end:
                    temp[k] = index[j]
                    k += 1
                    j += 1
                    
                index[start: end+1] = temp[start: end+1]
        
        mergeSort(0, len(nums) - 1)
        return result
