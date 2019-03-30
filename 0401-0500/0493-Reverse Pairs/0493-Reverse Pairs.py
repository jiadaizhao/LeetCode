class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        temp = [0]*len(nums)
        def mergeSort(start, end):
            count = 0
            if start < end:
                mid = (start + end) // 2
                count += mergeSort(start, mid)
                count += mergeSort(mid + 1, end)
                
                i = k = start
                j = p = mid + 1
                while i <= mid:
                    while p <= end and nums[i] > 2*nums[p]:
                        p += 1
                    count += p - (mid+1)
                    while j <= end and nums[i] > nums[j]:
                        temp[k] = nums[j]
                        k += 1
                        j += 1
                        
                    temp[k] = nums[i]
                    k += 1
                    i += 1
                    
                while j <= end:
                    temp[k] = nums[j]
                    k += 1
                    j += 1
                    
                nums[start:end+1] = temp[start:end+1]
            return count
        
        return mergeSort(0, len(nums) - 1)
