class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        grayCode = [i ^ (i >> 1) for i in range(1 << n)]
        index = grayCode.index(start)
        return grayCode[index:] + grayCode[:index]


class Solution2:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        return [start ^ i ^ (i >> 1) for i in range(1 << n)]
