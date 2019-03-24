class Solution:
    def splitArray(self, nums: 'List[int]', m: 'int') -> 'int':
        low, high = max(nums), sum(nums)
        def doable(target):
            count = 1
            sum = 0
            for num in nums:
                if sum + num > target:
                    count += 1
                    if count > m:
                        return False
                    sum = num
                else:
                    sum += num
            return True

        while low < high:
            mid = (low + high) // 2
            if doable(mid):
                high = mid
            else:
                low = mid + 1
        return low
