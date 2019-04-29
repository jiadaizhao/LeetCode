class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        counts = [0] * 121
        presum = [0] * 121
        for age in ages:
            counts[age] += 1
        for i in range(1, 121):
            presum[i] = presum[i - 1] + counts[i]
        result = 0
        # 0.5*A + 7 < B <= A
        for i in range(15, 121):
            if counts[i] == 0:
                continue
            result += (presum[i] - presum[i // 2 + 7] - 1) * counts[i]
        return result
