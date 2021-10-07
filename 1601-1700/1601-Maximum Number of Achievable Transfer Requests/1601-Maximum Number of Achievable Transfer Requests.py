class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        maxNum = 0
        net = [0] * n
        def dfs(curr, net, num):
            if curr == len(requests):
                if not any(net):
                    nonlocal maxNum
                    maxNum = max(maxNum, num)
                return
            
            net[requests[curr][0]] += 1
            net[requests[curr][1]] -= 1
            dfs(curr + 1, net, num + 1)
            net[requests[curr][0]] -= 1
            net[requests[curr][1]] += 1
            
            if requests[curr][0] != requests[curr][1]:
                dfs(curr + 1, net, num)
        dfs(0, net, 0)
        return maxNum
