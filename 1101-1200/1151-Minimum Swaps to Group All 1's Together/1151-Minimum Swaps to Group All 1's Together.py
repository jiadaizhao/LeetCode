class Solution:
    def minSwaps(self, data: List[int]) -> int:
        target = data.count(1)
        count = 0
        minS = len(data)
        for i in range(len(data)):
            if data[i] == 1:
                count += 1
            if i >= target - 1:
                if i >= target and data[i - target] == 1:
                    count -= 1
                minS = min(minS, target - count)
        return minS
