class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        index = [i for i, num in enumerate(nums) if num & 1]
        total = 0
        for i in range(len(index) - k + 1):
            j = i + k - 1
            total += (index[i] - (index[i - 1] if i > 0 else -1)) * \
                ((index[j + 1] if j < len(index) - 1 else len(nums)) - index[j])
        return total
