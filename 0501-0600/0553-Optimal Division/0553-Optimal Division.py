class Solution:
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        s = list(map(str, nums))
        if len(nums) <= 2:
            return '/'.join(s)

        return '{}/({})'.format(s[0], '/'.join(s[1:]))
