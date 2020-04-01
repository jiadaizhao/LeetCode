class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0
        
        min1 = min2 = -1
        for i in range(len(costs)):
            currMin1 = currMin2 = -1
            for j in range(len(costs[i])):
                if j != min1:
                    if i > 0:
                        costs[i][j] += costs[i - 1][min1]
                else:
                    costs[i][j] += costs[i - 1][min2]
                
                if currMin1 == -1 or costs[i][j] < costs[i][currMin1]:
                    currMin2 = currMin1
                    currMin1 = j
                elif currMin2 == -1 or costs[i][j] < costs[i][currMin2]:
                    currMin2 = j
            min1, min2 = currMin1, currMin2
        
        return costs[-1][min1]
