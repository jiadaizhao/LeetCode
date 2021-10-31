class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        St = []
        remove = len(nums) - k
        for num in nums:
            while St and num < St[-1] and remove > 0:
                St.pop()
                remove -= 1
            St.append(num)
        return St[:len(St) - remove]
