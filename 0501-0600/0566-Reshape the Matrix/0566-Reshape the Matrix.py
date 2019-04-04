class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if len(nums) * len(nums[0]) != r * c:
            return nums
        index = 0
        result = [[0]*c for _ in range(r)]
        for row in nums:
            for val in row:
                result[index // c][index % c] = val
                index += 1
        return result
