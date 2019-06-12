class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        result = []
        carry = 0
        i = len(arr1) - 1
        j = len(arr2) - 1
        while i >= 0 or j >= 0 or carry:
            s = carry
            if i >= 0:
                s += arr1[i]
                i -= 1
            if j >= 0:
                s += arr2[j]
                j -= 1
            result.append(s & 1)
            carry = -(s >> 1)

        while len(result) > 1 and result[-1] == 0:
            result.pop()

        return result[::-1]
