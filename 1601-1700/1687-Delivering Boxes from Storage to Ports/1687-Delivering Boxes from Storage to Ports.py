class Solution:
    def boxDelivering(self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int) -> int:
        n = len(boxes)
        samePort = [i == n - 1 or boxes[i][0] == boxes[i + 1][0] for i in range(n)]
        dp = [0] * (n + 1)
        start = weight = diff = 0
        for i, (p, w) in enumerate(boxes):
            if i - start == maxBoxes:
                weight -= boxes[start][1]
                if not samePort[start]:
                    diff -= 1
                start += 1
            weight += w
            if i > 0 and not samePort[i - 1]:
                diff += 1
            while weight > maxWeight:
                weight -= boxes[start][1]
                if not samePort[start]:
                    diff -= 1
                start += 1
            while start < i and dp[start] == dp[start + 1]:
                weight -= boxes[start][1]
                if not samePort[start]:
                    diff -= 1
                start += 1
            dp[i + 1] = diff + 2 + dp[start]
        
        return dp[n]
