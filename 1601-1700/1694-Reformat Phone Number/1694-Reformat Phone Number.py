class Solution:
    def reformatNumber(self, number: str) -> str:
        nums = [num for num in number if num.isdigit()]
        result = []
        n = len(nums)
        start = 0
        while n > 4:
            result.append(''.join(nums[start: start+3]))
            start += 3
            n -= 3
        if n == 4:
            result.append(''.join(nums[start: start+2]) + '-' +
                          ''.join(nums[start+2: start+4]))
        else:
            result.append(''.join(nums[start: start + n]))
        return '-'.join(result)
