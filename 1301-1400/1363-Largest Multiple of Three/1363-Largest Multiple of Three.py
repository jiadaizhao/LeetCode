import collections
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:        
        count = collections.Counter(digits)
        remain1Count = count[1] + count[4] + count[7]
        remain2Count = count[2] + count[5] + count[8]
        total = sum(digits)
        if total % 3 == 1:
            if remain1Count > 0:
                remain1Count -= 1
            else:
                remain2Count -= 2
        elif total % 3 == 2:
            if remain2Count > 0:
                remain2Count -= 1
            else:
                remain1Count -= 2
        result = []
        for d in range(9, -1, -1):
            num = count[d]
            if d % 3 == 1:
                num = min(num, remain1Count)
                remain1Count -= num
            elif d % 3 == 2:
                num = min(num, remain2Count)
                remain2Count -= num
            result.append(str(d) * num)
        result = ''.join(result)
        return '0' if result and result[0] == '0' else result
