class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        temp = [0] * len(nums)
        def mergeSort(start, end):
            if start < end:
                mid = (start + end) // 2
                mergeSort(start, mid)
                mergeSort(mid + 1, end)
                i = k = start
                j = mid + 1
                while i <= mid:
                    while j <= end and nums[j] < nums[i]:
                        temp[k] = nums[j]
                        j += 1
                        k += 1
                    temp[k] = nums[i]
                    i += 1
                    k += 1
                while j <= end:
                    temp[k] = nums[j]
                    j += 1
                    k += 1
                nums[start: end + 1] = temp[start: end + 1]
        mergeSort(0, len(nums) - 1)
        return nums
