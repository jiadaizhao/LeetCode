class Solution:
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        counts = [0] * 121
        presum = [0] * 121
        for age in ages:
            counts[age] += 1
        for i in range(1, 121):
            presum[i] = presum[i - 1] + counts[i]
        result = 0
        for i in range(15, 121):
            if counts[i] == 0:
                continue
            count = presum[i] - presum[i // 2 + 7]
            result += count * counts[i] - counts[i]
        return result
